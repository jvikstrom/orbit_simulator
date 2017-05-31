#include <iostream>
#include "simulator.hpp"
#include "object.hpp"

int main(){
  double end = 200;
  simulator sim(0, end, 0.1);
  object earth(vec2(0,0), vec2(0,0), 5000000);
  earth.name = "earth";
  object obj(vec2(100, 0), vec2(0, -10000/3600), 10);
  obj.name = "rocket";
  sim.add(earth);
  sim.add(obj);

  while(sim.step() < end){}
}
