#include "enemy/bat.h"
#include "Godot.hpp"
#include "stats/stats.h"

using namespace godot;

void Bat::_register_methods() {
  register_method("_ready", &Bat::_ready);
  register_method("_process", &Bat::_process);
  register_method("_physics_process", &Bat::_physics_process);
  register_method("_on_Hurtbox_area_entered", &Bat::_on_Hurtbox_area_entered);
  register_method("_on_Stats_no_health", &Bat::_on_Stats_no_health);
}

Bat::Bat() {}

Bat::~Bat() {}

void Bat::_init() {}

void Bat::_ready() {
  _stats = cast_to<Stats>(get_node("Stats"));
}

void Bat::_process(float delta) {}

void Bat::_physics_process(float delta) {
  _knockback = _knockback.move_toward(Vector2(0, 0), 200 * delta);
  _knockback = move_and_slide(_knockback);
}

void Bat::_on_Hurtbox_area_entered(Area2D *area) {
  _stats->set_health(_stats->get_health() - 1);
  if (area->get_name() == "SwordHitbox") {
    // Get the SwordHitbox
    SwordHitbox *sword = Object::cast_to<SwordHitbox>(area);
    // Get the knockback vector
    _knockback = sword->knockback_vector * 120;
  }
}

void Bat::_on_Stats_no_health() { this->queue_free(); }
