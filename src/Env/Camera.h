#pragma once
#include <iostream>

#include "Vector.h"
#include "Ray.h"


namespace Tracer
{
	// The camera is the viewpoint of the scene.
	// It is the starting point of all casted rays.
	// The camera can be oriented in space via focal distance,
	//	width, height, focal position (origin), yaw and pitch.
	// The position of the initial point of direction for the first ray
	//	is calculated and translated according to the provided pitch and yaw
	//	whilst the consequtive directions are interpolated.
	class Camera
	{
	private:
		Vector o; // Origin of rays (focal point)

		// The grid through which we cast the rays is a plane,
		//	thus a point and two vectors provide its whole span.
		Vector pivot;
		Vector right;
		Vector down;

		int width, height;

	public:
		Camera();
		Camera(const int iwidth, const int iheight, 
				const float ifd, const Vector& ifo,
				const float xRot, const float yRot, const float zRot);

		Ray getRay(const int line, const int column);
		friend std::ostream& operator<<(std::ostream& os, const Camera& c);
	};
}
