#ifndef ANIMATIONS_H
#define ANIMATIONS_H

// #include <string.h>

#include <Godot.hpp>
#include <AnimationTree.hpp>
#include <AnimationNodeStateMachinePlayback.hpp>

using namespace godot;

class PlayerAnimations
{
private:
    Godot *_gd;
    // AnimationPlayer *_anim_player; // AnimationPlayer node
    // Animation tree
    AnimationTree *_anim_tree;
    AnimationNodeStateMachinePlayback *_anim_state;

public:
    // Registers needed methods in Godot
    static void _register_methods();

    // Constructor
    PlayerAnimations(AnimationTree *a_tree);
    // Destructor
    ~PlayerAnimations();

    // _init() is called when the object is created
    void _init();
    // _ready() is called when the node is added to the scene tree
    void _ready();

    void set_animation_direction(Vector2 direction);
    void set_animation_state(String state);
};

#endif
