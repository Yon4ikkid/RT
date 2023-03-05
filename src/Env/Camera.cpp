/**
 * @file Camera.cpp
 * @author Yon Kidalov
 * @brief Provides implementation for the Camera class
 * @version 0.1
 * @date 05-02-2023
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <cmath>
#include <exception>

#include "Camera.h"
#include "../Math/Matrix.h"

#define PI 3.1415926535f 
#define TO_RAD(D) (D * (PI / 180.0f))

using namespace Tracer;

Camera::Camera() : width(0), height(0), focalDistance(0) { }

/**
 * @brief Construct a new Camera:: Camera object
 * 
 * @param iwidth - camera width
 * @param iheight - camera height
 * @param ifd - camera focal distance (the distance between the camera position and the viewplane)
 * @param ifo - the position of the camera
 * @param xRot - rotation around x axis
 * @param yRot - rotation around y axis
 * @param zRot - rotation around z axis
 * @note rotation is in degrees
 */
Camera::Camera(const int iwidth, const int iheight, const float ifd,
	const Vector& ifo, const float xRot, const float yRot, const float zRot)
{
	this->focalDistance = ifd;
	o = ifo;
	this->width = iwidth;
	this->height = iheight;

	if (iwidth <= 0 || iheight <= 0)
		throw std::runtime_error("Camera size cannot be negative or zero");

	// At first the camera around the origin is constructed, aligned with the axes,
	//	and later it is rotated and translated as required
	Vector	a(-width / 2, ifd, height / 2),
			b(width / 2, ifd, height / 2),
			c(-width / 2, ifd, -height / 2);

	
	// Create rotation matrix
	Matrix rotMatrix;
	float zRad = TO_RAD(-zRot), yRad = TO_RAD(-yRot), xRad = TO_RAD(-xRot);
	float sinA = sinf(zRad), sinB = sinf(yRad), sinG = sinf(xRad);
	float cosA = cosf(zRad), cosB = cosf(yRad), cosG = cosf(xRad);

	rotMatrix.v[0][0] = cosA * cosB;
	rotMatrix.v[0][1] = cosA * sinB * sinG - sinA * cosG;
	rotMatrix.v[0][2] = cosA * sinB * cosG + sinA * sinG;
	rotMatrix.v[1][0] = sinA * cosB;
	rotMatrix.v[1][1] = sinA * sinB * sinG + cosA * cosG;
	rotMatrix.v[1][2] = sinA * sinB * cosG - cosA * sinG;
	rotMatrix.v[2][0] = -sinB;
	rotMatrix.v[2][1] = cosB * sinG;
	rotMatrix.v[2][2] = cosB * cosG;
	

	// Translate points
	a = rotMatrix * a + ifo;
	b = rotMatrix * b + ifo;
	c = rotMatrix * c + ifo;
	
	// Construct the boundary rays
	this->right = (b - a).unit();
	this->down = (c - a).unit();
	this->pivot = a;
}

/**
 * @brief Returns the ray for a pixel given by the line and column in the camera
 * 
 * @param line - pixel line
 * @param column - pixel column
 * @return Ray - ray passing from the camera origin to the pixel's virtual position
 */
Ray Camera::get_ray(const int line, const int column)
{
	if (line > this->height || column > this->width || line <= 0 || column <= 0)
		throw std::runtime_error("Ray request out of camera bounds");
	
	// Calculate the direction pivot vector of the ray (middle of pixel in space)
	Vector d = this->pivot + this->right * (column - 0.5f) + this->down * (line - 0.5f);
	
	return Ray(this->o, (d - this->o).unit());
}

/**
 * @brief Stream insertion operator
 * 
 * @param os - output stream
 * @param c - camera
 * @return std::ostream& 
 */
std::ostream& Tracer::operator<<(std::ostream& os, const Camera& c)
{
	os << "H: " << c.height << " W: " << c.width << '\n';
	os << "Pivot: " << c.pivot << '\n';
	os << "Right: " << c.right << '\n';
	os << "Down: " << c.down << '\n';

	return os;
}

int Camera::get_width() const
{
	return this->width;
}

int Camera::get_height() const
{
	return this->height;
}
