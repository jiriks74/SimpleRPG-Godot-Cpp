#include "stats/stats.h"

void Stats::_register_methods() {
  register_method("_ready", &Stats::_ready);
  register_method("_process", &Stats::_process);
  register_method("_physics_process", &Stats::_physics_process);

  register_signal<Stats>("no_health");

  register_property<Stats, int>("MAX HEALTH", &Stats::MAX_HEALTH, 1);
}

void Stats::set_health(int hp) {
  if (hp <= 0) {
    emit_signal("no_health");
    _health = 0;
  }
  else if (hp > MAX_HEALTH) {
    _health = MAX_HEALTH;
  }
  else {
    _health = hp;
  }
}

int Stats::get_health() { return _health; }

Stats::Stats() {
  // Initialize any variables here
}

Stats::~Stats() {
  // Free any memory here
}

void Stats::_init() {
  // Initialize any variables here
  MAX_HEALTH = 1;
}

void Stats::_ready() {
  // Called every time the node is added to the scene.
  // Initialization here
  _health = MAX_HEALTH;
  // emit_signal("no_health");
}

void Stats::_process(float delta) {
  // Called every frame. Delta is time since last frame.
  // Update game logic here.
}

void Stats::_physics_process(float delta) {
  // Called every physics frame. Delta is time since last frame.
  // Update game physics here.
}
