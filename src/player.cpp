#include "player.h"
#include <iostream>

using namespace godot;

// Registeres needed methods in Godot
// We do not have to pass the _init function because it is called automatically
void player::_register_methods()
{
    register_method("_ready", &player::_ready);
    register_method("_process", &player::_process);
    register_method("_physics_process", &player::_physics_process);
    
    register_property<player, float>("acceleration", &player::_ACCELERATION, 12);
    register_property<player, float>("max_speed", &player::_MAX_SPEED, 125);
    register_property<player, float>("friction", &player::_FRICION, 10);
}

// Constructor
player::player()
{
    // Initialize member variables here
}

// Destructor
player::~player()
{
    // Free any memory here
}

// _init() is called when the object is created
void player::_init()
{
    // Initialize any variables here
    _ACCELERATION = 400;
    _MAX_SPEED = 100;
    _FRICION = 10;
}

// _ready() is called when the node is added to the scene tree
void player::_ready()
{
    // Called every time the node is added to the scene.
    // Initialization here
    _in = godot::Input::get_singleton();
}

// _process() is called every frame
// delta is the time since the last frame (prevents speeding up when fps is high and slowing down when fps is low)
void player::_process(float delta)
{
    // Called every frame. Delta is time since last frame.
}

void player::_physics_process(float delta)
{
    // Called every physics frame
    Vector2 input_vector = Vector2(0, 0);
    input_vector.x = _in->get_action_strength("ui_right") - _in->get_action_strength("ui_left");
    input_vector.y = _in->get_action_strength("ui_down") - _in->get_action_strength("ui_up");
    input_vector = input_vector.normalized();

    if(input_vector != Vector2(0, 0))
    {
        _vel = _vel.move_toward(input_vector * _MAX_SPEED, _ACCELERATION);
    }
    else{
        _vel = _vel.move_toward(Vector2(0, 0), _FRICION);
    }

    // move_and_collide(_vel * delta);
    _vel = move_and_slide(_vel);
}
