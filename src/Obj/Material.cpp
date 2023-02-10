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

Material::Material() : rdr(0), color{ 255, 0, 0 } { }

Tracer::Material::Material(const int r, const int g, const int b, const float irdr) : rdr(irdr), color{ r, g, b } { }

Material::Material(const int color[3], const float rdr)
	: Material(color[0], color[1], color[2], rdr) { }
