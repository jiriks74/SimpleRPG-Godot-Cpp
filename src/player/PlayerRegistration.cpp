#include "player/PlayerRegistration.h"

#include "player/Player.h"
#include "player/SwordHitbox.h"

void PlayerRegistration::register_classes()
{
    godot::register_class<Player>();
    godot::register_class<SwordHitbox>();
}
