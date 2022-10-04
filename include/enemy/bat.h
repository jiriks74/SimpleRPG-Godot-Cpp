#ifndef BAT_H
#define BAT_H

#include <Godot.hpp>
#include <KinematicBody2D.hpp>
#include <Area2D.hpp>
#include <Vector2.hpp>

#include "player/SwordHitbox.h"
#include "stats/stats.h"

using namespace godot;

class Bat : public KinematicBody2D{
    GODOT_CLASS(Bat, KinematicBody2D)

  private:
    Vector2 _knockback;
    Godot* _gd;
    // Stats object
    Stats* _stats;

  public:
    static void _register_methods();

    Bat();
    ~Bat();

    void _init();
    void _ready();
    void _process(float delta);
    void _physics_process(float delta);
    void _on_Hurtbox_area_entered(Area2D* area);

    void _on_Stats_no_health();
};

#endif
