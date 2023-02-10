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
	private:
		Vector o;
		
		Vector pivot;
		Vector right;
		Vector down;

		int width, height;

	public:
		Camera();
		Camera(const int iwidth, const int iheight, 
				const float ifd, const Vector& ifo,
				const float xRot, const float yRot, const float zRot);

		Ray get_ray(const int line, const int column);
		friend std::ostream& operator<<(std::ostream& os, const Camera& c);
	};
}
