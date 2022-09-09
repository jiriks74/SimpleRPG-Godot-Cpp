// Setup basic godot headder with player class

#ifndef PLAYER_H
#define PLAYER_H

#include <Godot.hpp>
#include <KinematicBody2D.hpp>
#include <Input.hpp>
#include <KinematicBody2D.hpp>
#include <KinematicCollision2D.hpp>

namespace godot
{
    class player : public KinematicBody2D
    {
        // Godot class macros
        GODOT_CLASS(player, KinematicBody2D)

    private:
        float _ACCELERATION;
        float _MAX_SPEED;
        float _FRICION;

        godot::Godot *_gd;
        godot::Input *_in;
        godot::KinematicBody2D *_body;

        Vector2 _vel = Vector2(0, 0);

    public:
        // Registeres needed methods in Godot
        static void _register_methods();

        // Constructor
        player();
        // Destructor
        ~player();

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
    };
}

#endif