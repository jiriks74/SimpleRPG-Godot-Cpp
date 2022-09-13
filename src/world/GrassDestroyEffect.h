#ifndef GRASSDESTROYEFFECT_H
#define GRASSDESTROYEFFECT_H

#include <Godot.hpp>
#include <Node2D.hpp>
#include <AnimatedSprite.hpp>

using namespace godot;

class GrassDestroyEffect : public Node2D
{
    GODOT_CLASS(GrassDestroyEffect, Node2D)

private:
    AnimatedSprite *_animatedSprite;

public:
    static void _register_methods();

    GrassDestroyEffect();
    ~GrassDestroyEffect();

    void _init();
    void _ready();
    void _process(float delta);
    void _physics_process(float delta);
    void _on_AnimatedSprite_animation_finished();
};

#endif // GRASSDESTROYEFFECT_H