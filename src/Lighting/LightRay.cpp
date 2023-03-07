#include "LightRay.h"

using namespace Tracer;

LightRay::LightRay() { }

LightRay::LightRay(Vector o, Vector d, float i) : Ray(o,d), intensity(i) { }
