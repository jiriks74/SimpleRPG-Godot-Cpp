#ifndef STATS_H
#define STATS_H

#include <Godot.hpp>
#include <Node.hpp>

using namespace godot;

class Stats : public Node {
  GODOT_CLASS(Stats, Node)

private:
  int _health;

public:
  static void _register_methods();
  Stats();
  ~Stats();

  // Stats variables
  int MAX_HEALTH;

  void _init();
  void _ready();
  void _process(float delta);
  void _physics_process(float delta);

  // Getters and setters
  void set_health(int hp);
  int get_health();
};

#endif // STATS_H
