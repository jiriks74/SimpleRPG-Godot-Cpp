#include "Player.h"

// Registeres needed methods in Godot
// We do not have to pass the _init function because it is called automatically
void Player::_register_methods()
{
    register_method("_ready", &Player::_ready);
    register_method("_process", &Player::_process);
    register_method("_physics_process", &Player::_physics_process);
    register_method("end_attack", &Player::end_attack);
    
    register_property<Player, float>("acceleration", &Player::_ACCELERATION, 12);
    register_property<Player, float>("max_speed", &Player::_MAX_SPEED, 125);
    register_property<Player, float>("friction", &Player::_FRICION, 12);
}

// Constructor
Player::Player()
{
    // Initialize member variables here
}

// Destructor
Player::~Player()
{
    // Free any memory here
}

// _init() is called when the object is created
void Player::_init()
{
    // Initialize any variables here
    _ACCELERATION = 12;
    _MAX_SPEED = 125;
    _FRICION = 12;
}

// _ready() is called when the node is added to the scene tree
void Player::_ready()
{
    // Get the godot object
    // Called every time the node is added to the scene.
    // Initialization here
    // Input::get_singleton() returns a pointer to the Input object
    _in = _in->get_singleton();
    AnimationTree *a_tree;
    a_tree = cast_to<AnimationTree>(get_node("AnimationTree"));
    _anim = new PlayerAnimations(a_tree);
}

// _process() is called every frame
// delta is the time since the last frame (prevents speeding up when fps is high and slowing down when fps is low)
void Player::_process(float delta)
{
    // Called every frame. Delta is time since last frame.
}

void Player::_physics_process(float delta)
{
    switch(_state){
        case Move:
            move_state(delta);
            break;
        case Attack:
            attack_state(delta);
            break;
        case Roll:
            break;
    }
}

// Function for move state
void Player::move_state(float delta)
{
    // Called every physics frame
    // delta is the time since the last frame (prevents speeding up when fps is high and slowing down when fps is low)
    // Get the input
    Vector2 input_vector = Vector2(0, 0);
    // Get the strengths of the left and right input and subtract them to get the final horizontal input
    input_vector.x = _in->get_action_strength("ui_right") - _in->get_action_strength("ui_left");
    // Get the strengths of the up and down input and subtract them to get the final vertical input
    input_vector.y = _in->get_action_strength("ui_down") - _in->get_action_strength("ui_up");
    // Normalize the input vector to get a vector with a length of 1 - this is needed to get the same speed when moving diagonally
    input_vector = input_vector.normalized();

    // Check if the input vector is not zero - user is pressing a key
    if(input_vector != Vector2(0, 0))
    {
        // Set the animation direction
        _anim->set_animation_direction(input_vector);
        _anim->set_animation_state("Run");

        // Add the input vector to the velocity
        _vel = _vel.move_toward(input_vector * _MAX_SPEED, _ACCELERATION);
    }
    else{
        // Set the animation state to idle
        _anim->set_animation_state("Idle");
        // Slow down the player
        _vel = _vel.move_toward(Vector2(0, 0), _FRICION);
    }

    // Move the player
    _vel = move_and_slide(_vel);

    if(_in->is_action_just_pressed("attack")){
        _state = Attack;
    }
}

void Player::attack_state(float delta){
    _anim->set_animation_state("Attack");
    _vel = Vector2(0, 0);
}

void Player::end_attack(){
    _state = Move;
}