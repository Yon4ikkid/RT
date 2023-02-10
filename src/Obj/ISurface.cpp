/**
 * @file ISurface.cpp
 * @author Yon Kidalov (yon4ikkid@gmail.com)
 * @brief Provides implementation for the ISurface interface
 * @version 0.1
 * @date 05-02-2023
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "ISurface.h"

using namespace Tracer;

/**
 * @brief Construct a new ISurface::ISurface object
 * 
 * @param material 
 */
ISurface::ISurface(const Material& material) : surface_material(material) { }

/**
 * @brief Returns the surface material
 * 
 * @return Material 
 */
Material ISurface::get_material() const
{
	return surface_material;
}
