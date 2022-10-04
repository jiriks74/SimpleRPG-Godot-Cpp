#ifndef PLAYER_H
#define PLAYER_H

#include <AnimationTree.hpp>
#include <Godot.hpp>
#include <Input.hpp>
#include <KinematicBody2D.hpp>
#include <ResourceLoader.hpp>
#include <SceneTree.hpp>
#include <Vector2.hpp>
#include <Area2D.hpp>
#include <PackedScene.hpp>
#include <ResourceLoader.hpp>

#include "PlayerAnimations.h"
#include "SwordHitbox.h"

using namespace godot;

class Player : public KinematicBody2D {
  // Godot class macros
  GODOT_CLASS(Player, KinematicBody2D)

private:
  // Variables accessible from Godot's UI
  float _ACCELERATION;
  float _MAX_SPEED;
  float _FRICION;
  float _ROLL_SPEED;

  // Velocity of the player (has to be persistenst between frames)
  Vector2 _vel = Vector2(0, 0);
  // Roll vector
  Vector2 _roll_vector = Vector2(1, 0);

  // Objects pointers
  Godot *_gd; // Godot object
  Input *_in; // Input object
  PlayerAnimations *_anim;

  enum PLAYER_STATE { Move, Attack, Roll };

  PLAYER_STATE _state = Move;

  // Sword hitbox node
  SwordHitbox *sword_hitbox;

  // Function move state
  void move();

public:
  // Registers needed methods in Godot
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
  // delta is the time since the last frame (prevents speeding up when fps is
  // high and slowing down when fps is low)
  void _process(float delta);
  // _physics_process() is called every physics frame
  // delta is the time since the last frame (prevents speeding up when fps is
  // high and slowing down when fps is low)
  void _physics_process(float delta);
  void move_state(float delta);
  void attack_state(float delta);
  void roll_state(float delta);
  void end_attack();
  void end_roll();
};

#endif
