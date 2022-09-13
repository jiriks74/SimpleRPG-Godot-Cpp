#include "PlayerRegistration.h"

#include "Player.h"

void PlayerRegistration::register_classes()
{
    godot::register_class<Player>();
}