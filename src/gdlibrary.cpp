#include "player/PlayerRegistration.h"
#include "world/WorldRegistration.h"

#include "enemy/bat.h"
#include "stats/stats.h"

#include <Godot.hpp>

extern "C" void GDN_EXPORT godot_gdnative_init(godot_gdnative_init_options *o) {
    godot::Godot::gdnative_init(o);
}

extern "C" void GDN_EXPORT godot_gdnative_terminate(godot_gdnative_terminate_options *o) {
    godot::Godot::gdnative_terminate(o);
}

extern "C" void GDN_EXPORT godot_nativescript_init(void *handle) {
    godot::Godot::nativescript_init(handle);

    PlayerRegistration::register_classes();
    WorldRegistration::register_classes();

    godot::register_class<Bat>();
    godot::register_class<Stats>();
}
