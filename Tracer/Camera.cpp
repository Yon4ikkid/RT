#include <cmath>
#include <exception>

#include "Camera.h"
#include "Matrix.h"

#define PI 3.1415926535f 
#define TO_RAD(D) (D * (PI / 180.0f))

using namespace Tracer;

Camera::Camera(const int iwidth, const int iheight, const float ifd,
	const Vector& ifo, const float xRot, const float yRot, const float zRot)
{
	__o = ifo;
	__width = iwidth;
	__height = iheight;

	if (iwidth <= 0 || iheight <= 0)
		throw std::runtime_error("Camera size cannot be negative or zero");

	// At first the camera around the origin is constructed, aligned with the axes,
	//	and later it is rotated and translated as required
	Vector	a(-__width / 2, ifd, __height / 2),
			b(__width / 2, ifd, __height / 2),
			c(-__width / 2, ifd, -__height / 2);

	
	// Create rotation matrix
	Matrix rotMatrix;
	float zRad = TO_RAD(-zRot), yRad = TO_RAD(-yRot), xRad = TO_RAD(-xRot);
	float sinA = sinf(zRad), sinB = sinf(yRad), sinG = sinf(xRad);
	float cosA = cosf(zRad), cosB = cosf(yRad), cosG = cosf(xRad);

	rotMatrix.__v[0][0] = cosA * cosB;
	rotMatrix.__v[0][1] = cosA * sinB * sinG - sinA * cosG;
	rotMatrix.__v[0][2] = cosA * sinB * cosG + sinA * sinG;
	rotMatrix.__v[1][0] = sinA * cosB;
	rotMatrix.__v[1][1] = sinA * sinB * sinG + cosA * cosG;
	rotMatrix.__v[1][2] = sinA * sinB * cosG - cosA * sinG;
	rotMatrix.__v[2][0] = -sinB;
	rotMatrix.__v[2][1] = cosB * sinG;
	rotMatrix.__v[2][2] = cosB * cosG;
	

	// Translate points
	a = rotMatrix * a + ifo;
	b = rotMatrix * b + ifo;
	c = rotMatrix * c + ifo;
	
	// Construct the boundary rays
	__right = (b - a).unit();
	__down = (c - a).unit();
	//__xRay = Ray(a, (b - a).unit());
	//__yRay = Ray(a, (c - a).unit());
}

Ray Tracer::Camera::getNextRay()
{
	float tX = __rC - 0.5f;
	float tY = __dC - 0.5f;

	Vector d = __pivot + __right * __rC + __down * __dC;

	__rC++;
	if (__rC % __width == 0)
	{
		__rC = 0;
		__dC++;
	}
	if (__dC >= __height)
	{
		throw std::runtime_error("Cannot generate rays beyond camera limits");
	}

	return Ray(__o, d);
}

std::ostream& Tracer::operator<<(std::ostream& os, const Camera& c)
{
	os << "H: " << c.__height << " W: " << c.__width << '\n';
	os << "Pivot: " << c.__pivot << '\n';
	os << "Right: " << c.__right << '\n';
	os << "Down: " << c.__down << '\n';

	return os;
}
