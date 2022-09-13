#include "PlayerAnimations.h"

using namespace godot;

// Constructor
PlayerAnimations::PlayerAnimations(AnimationTree *a_tree)
{
    // Initialize member variables here
    _anim_tree = a_tree;
    // Get the AnimationNodeStateMachinePlayback node object
    _anim_state = _anim_tree->get("parameters/playback");

    // Activate the animation tree
    _anim_tree->set_active(true);
}

// Destructor
PlayerAnimations::~PlayerAnimations()
{
    // Free any memory here
}

void PlayerAnimations::set_animation_direction(Vector2 diretcion)
{
    _anim_tree->set("parameters/Idle/blend_position", diretcion);
    _anim_tree->set("parameters/Run/blend_position", diretcion);
    _anim_tree->set("parameters/Attack/blend_position", diretcion);
}

void PlayerAnimations::set_animation_state(String state)
{
    if(state == "Idle")
    {
        _anim_state->travel("Idle");
    }
    else if(state == "Run")
    {
        _anim_state->travel("Run");
    }
    else if(state == "Attack")
    {
        _anim_state->travel("Attack");
    }
}