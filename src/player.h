// Setup basic godot headder with player class

#ifndef PLAYER_H
#define PLAYER_H

#include <Godot.hpp>
#include <KinematicBody2D.hpp>

namespace godot{
    class player : public KinematicBody2D{
        // Godot class macros
        GODOT_CLASS(player, KinematicBody2D)

    private:
    // Create gd struct from godot::Godot
    godot::Godot *gd;


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
};
}

#endif