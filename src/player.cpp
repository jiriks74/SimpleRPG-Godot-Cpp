#include "player.h"
#include <iostream>

using namespace godot;

// Registeres needed methods in Godot
// We do not have to pass the _init function because it is called automatically
void player::_register_methods(){
    register_method("_ready", &player::_ready);
    register_method("_process", &player::_process);
}

// Constructor
player::player(){
    // Initialize member variables here
}

// Destructor
player::~player(){
    // Free any memory here
}

// _init() is called when the object is created
void player::_init(){
    // Initialize any variables here
}

// _ready() is called when the node is added to the scene tree
void player::_ready(){
    // Called every time the node is added to the scene.
    // Initialization here
    gd->print("Hello World!");
}

// _process() is called every frame
// delta is the time since the last frame (prevents speeding up when fps is high and slowing down when fps is low)
void player::_process(float delta){
    // Called every frame. Delta is time since last frame.
    // Update game logic here.
}
