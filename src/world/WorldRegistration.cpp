#include "world/WorldRegistration.h"

#include "world/Grass.h"
#include "world/GrassDestroyEffect.h"

void WorldRegistration::register_classes()
{
    register_class<GrassDestroyEffect>();
    register_class<Grass>();
}
