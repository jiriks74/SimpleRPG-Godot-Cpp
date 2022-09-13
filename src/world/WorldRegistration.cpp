#include "WorldRegistration.h"

#include "Grass.h"
#include "GrassDestroyEffect.h"

void WorldRegistration::register_classes()
{
    register_class<GrassDestroyEffect>();
    register_class<Grass>();
}