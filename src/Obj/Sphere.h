/**
 * @file Sphere.h
 * @author Yon Kidalov
 * @brief Defines the Sphere surface class
 * @version 0.1
 * @date 05-02-2023
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once
#include "ISurface.h"
#include "../Math/Vector.h"


namespace Tracer
{
	class Sphere : public ISurface
	{
	private:
		Vector centre;
		float radius;

	protected:
		Vector get_normal(const Vector& p) const override;

	public:
		Sphere();
		Sphere(const Vector& center, const float radius);
		Vector get_centre() const;
		std::optional<float> intersect(const Ray& r) override;
	};
}
