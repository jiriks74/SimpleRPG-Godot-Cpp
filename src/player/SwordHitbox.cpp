#include "player/SwordHitbox.h"

void SwordHitbox::_register_methods(){
  register_method("_ready", &SwordHitbox::_ready);
  register_method("_process", &SwordHitbox::_process);
  register_method("_physics_process", &SwordHitbox::_physics_process);
}

SwordHitbox::SwordHitbox(){
}

SwordHitbox::~SwordHitbox(){
}

void SwordHitbox::_init(){
}

void SwordHitbox::_ready(){
}

void SwordHitbox::_process(float delta){
}

void SwordHitbox::_physics_process(float delta){
}
