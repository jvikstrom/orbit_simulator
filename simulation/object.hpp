#pragma once

#include "logger.hpp"
#include "vec2.hpp"

class object{
public:
  vec2 position;
  vec2 velocity;
  double mass;
  std::string name;
  object(vec2 position = vec2(), vec2 velocity = vec2(), double mass = 0) : position(position), velocity(velocity), mass(mass){}

  vec2 calcForce(const object& obj);
  void applyForce(const vec2& force);
  void step(double timestep);
};
