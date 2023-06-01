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
Material::Material() : roughness(0), transmission(0), color{ 255, 0, 0 } { }

/**
 * @brief Construct a new Tracer:: Material:: Material object
 * 
 * @param r - red
 * @param g - green
 * @param b - blue
 * @param irdr - reflective direction randomization factor (diffusive reflection)
 */
Tracer::Material::Material(const int r, const int g, const int b, const float irdr, const float trn) : roughness(irdr), transmission(trn), color{ r, g, b } { }

/**
 * @brief Construct a new Material:: Material object
 * 
 * @param color - rgb color
 * @param rdr - reflective direction randomization factor (diffusive reflection)
 */
Material::Material(const int color[3], const float rdr, const float tnr)
	: Material(color[0], color[1], color[2], rdr, tnr) { }
