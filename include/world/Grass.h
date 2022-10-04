#ifndef GRASS_H
#define GRASS_H

#include <Godot.hpp>
#include <Node2D.hpp>
#include <PackedScene.hpp>
#include <SceneTree.hpp>
#include <Area2D.hpp>
#include <ResourceLoader.hpp>

using namespace godot;

class Grass : public Node2D
{
    // Godot class macros
    GODOT_CLASS(Grass, Node2D)

private:
    Godot *_gd;
    SceneTree *tree;
    Ref<PackedScene> GrassEffect;

public:
    static void _register_methods();

    Grass();
    ~Grass();

    void _init();
    void _ready();
    void _process(float delta);
    void create_grass_effect();
    void _on_Hurtbox_area_entered(Area2D *area);
};

#endif // GRASS_H
