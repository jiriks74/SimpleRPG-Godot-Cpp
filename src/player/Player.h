#ifndef PLAYER_H
#define PLAYER_H

#include <Godot.hpp>
#include <Input.hpp>
#include <KinematicBody2D.hpp>
#include <AnimationTree.hpp>
#include <Vector2.hpp>

#include "PlayerAnimations.h"

using namespace godot;

class Player : public KinematicBody2D
{
    // Godot class macros
    GODOT_CLASS(Player, KinematicBody2D)

private:
    // Variables accessible from Godot's UI
    float _ACCELERATION;
    float _MAX_SPEED;
    float _FRICION;

    // Velocity of the player (has to be persistenst between frames)
    Vector2 _vel = Vector2(0, 0);

    // Objects pointers
    Godot *_gd;             // Godot object
    Input *_in;             // Input object
    PlayerAnimations *_anim;

    enum PLAYER_STATE
    {
        Move,
        Attack,
        Roll
    };

    PLAYER_STATE _state = Move;

public:
    // Registeres needed methods in Godot
    static void _register_methods();

    // Constructor
    Player();
    // Destructor
    ~Player();

    // _init() is called when the object is created
    void _init();
    // _ready() is called when the node is added to the scene tree
    void _ready();
    // _process() is called every frame
    // delta is the time since the last frame (prevents speeding up when fps is high and slowing down when fps is low)
    void _process(float delta);
    // _physics_process() is called every physics frame
    // delta is the time since the last frame (prevents speeding up when fps is high and slowing down when fps is low)
    void _physics_process(float delta);
    void move_state(float delta);
    void attack_state(float delta);
    void end_attack();
};

#endif