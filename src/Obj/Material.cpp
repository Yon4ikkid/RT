/**
 * @file Material.cpp
 * @author Yon Kidalov (yon4ikkid@gmail.com)
 * @brief Provides implementation for the Material struct
 * @version 0.1
 * @date 05-02-2023
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "Material.h"

using namespace Tracer;

/**
 * @brief Construct a new Material:: Material object - default
 * 
 */
Material::Material() : roughness(0), transmission(0), color({ 1.0, 0, 0 }) { }

/**
 * @brief Construct a new Tracer:: Material:: Material object
 * 
 * @param r - red
 * @param g - green
 * @param b - blue
 * @param irdr - reflective direction randomization factor (diffusive reflection)
 */
Tracer::Material::Material(const float r, const float g, const float b, const float irdr, const float trn) : roughness(irdr), transmission(trn), color{ r, g, b }
{
	this->color = Vector(r / 255.0, g / 255.0, b / 255.0);
}
