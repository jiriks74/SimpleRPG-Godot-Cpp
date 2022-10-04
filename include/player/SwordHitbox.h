#ifndef SWORDHITBOX_H
#define SWORDHITBOX_H

#include "Vector2.hpp"
#include <Godot.hpp>
#include <Area2D.hpp>
#include <Vector2.hpp>

using namespace godot;

class SwordHitbox : public Area2D {
    GODOT_CLASS(SwordHitbox, Area2D)

    public:
      static void _register_methods();

      SwordHitbox();
      ~SwordHitbox();
      void _init();
      void _ready();
      void _process(float delta);
      void _physics_process(float delta);

      Vector2 knockback_vector;
};

#endif // SWORDHITBOX_H
