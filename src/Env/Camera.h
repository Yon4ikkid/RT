/**
 * @file Camera.h
 * @author Yon Kidalov
 * @brief Defines the Camera class
 * @version 0.1
 * @date 05-02-2023
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once
#include <iostream>

#include "../Math/Vector.h"
#include "../Render/Ray.h"

namespace Tracer
{
	class Camera
	{
	friend std::ostream& operator<<(std::ostream& os, const Camera& c);

	private:
		Vector o;
		
		Vector pivot;
		Vector right;
		Vector down;

		int width, height;
		float focalDistance;
	public:
		Camera();
		Camera(const int iwidth, const int iheight, 
				const float ifd, const Vector& ifo,
				const float xRot, const float yRot, const float zRot);

		int get_width() const;
		int get_height() const;
		Ray get_ray(const int line, const int column);
	};
}
