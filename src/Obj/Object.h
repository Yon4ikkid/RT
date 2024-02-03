#pragma once
#include "../Render/IRenderable.h"
#include "Material.h"
#include "ISurface.h"

namespace Tracer
{
    class Object: public IRenderable
    {
    private:
        Material surface_material;
        ISurface* surface;

    public:
        Object();
        Object(const Material surface_material, ISurface* const surface);
        Material get_material() const;

        virtual bool intersect(const Ray& r, Intersection& out) override;
		virtual ~Object();
    };
}
