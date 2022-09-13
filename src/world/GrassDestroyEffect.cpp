#include "GrassDestroyEffect.h"

void GrassDestroyEffect::_register_methods()
{
    register_method("_init", &GrassDestroyEffect::_init);
    register_method("_ready", &GrassDestroyEffect::_ready);
    register_method("_process", &GrassDestroyEffect::_process);
    register_method("_physics_process", &GrassDestroyEffect::_physics_process);
    register_method("_on_AnimatedSprite_animation_finished", &GrassDestroyEffect::_on_AnimatedSprite_animation_finished);
}

GrassDestroyEffect::GrassDestroyEffect()
{
}

GrassDestroyEffect::~GrassDestroyEffect()
{
} 

void GrassDestroyEffect::_init()
{
}

void GrassDestroyEffect::_ready()
{
    _animatedSprite = cast_to<AnimatedSprite>(get_node("AnimatedSprite"));
    _animatedSprite->set_frame(0);
    _animatedSprite->play("Animate");
}


void GrassDestroyEffect::_physics_process(float delta)
{
}

void GrassDestroyEffect::_process(float delta)
{
}

void GrassDestroyEffect::_on_AnimatedSprite_animation_finished()
{
    queue_free();
}