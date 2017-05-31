#include "object.hpp"

vec2 object::calcGravityForce(const object& obj){
  vec2 dir = obj.position - position;
  double F = G * mass * obj.mass / (std::pow(dir.norm(), 2));
  dir = dir.normalize();

  return F * dir;
}

void object::applyForce(const vec2& force){
  velocity += force / mass;
}

void object::step(double timestep){
  position += velocity * timestep;
}
