#include "Grass.h"

void Grass::_register_methods()
{
    register_method("_init", &Grass::_init);
    register_method("_ready", &Grass::_ready);
    register_method("_process", &Grass::_process);

    register_method("_on_Hurtbox_area_entered", &Grass::_on_Hurtbox_area_entered);
    register_property("Grass Effect Scene", &Grass::GrassEffect, (Ref<PackedScene>)nullptr);
}

Grass::Grass()
{
}

Grass::~Grass()
{
}

void Grass::_init()
{
}

void Grass::_ready()
{
}

void Grass::_process(float delta)
{
}

void Grass::create_grass_effect()
{
    // Get instance of the GrassEffect scene
    Node2D *effect = cast_to<Node2D>(GrassEffect->instance());
    // Get current scene
    Node *currentScene = get_tree()->get_current_scene();
    // Add effect to current scene
    currentScene->add_child(effect);
    effect->set_global_position(get_global_position());
}

void Grass::_on_Hurtbox_area_entered(Area2D *area){
    create_grass_effect();
    queue_free();
}