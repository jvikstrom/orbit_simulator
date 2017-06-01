#include <iostream>
#include <cmath>
#include "simulator.hpp"
#include "simulation_display.hpp"
#include "object.hpp"
#include "window.hpp"

int main(){
  int resolution = 1000;
  double end = 24*3600;
  simulator sim(0, end, 1);
  object earth(vec2(0,0), vec2(0,0), 5.972 * std::pow(10,24));
  earth.name = "earth";
  object obj(vec2(36 * std::pow(10, 6), 0), vec2(0, 3.07 * 1000), 10);
  obj.name = "rocket";
  sim.add(earth);
  sim.add(obj);

  gui::simulation_display disp(resolution, std::pow(10, 6), sim);
  disp.track("earth", gui::track_settings(true, vec2(12, 12)));
  disp.track("rocket", gui::track_settings(false, vec2(5,5)));
  disp.run();

  int q;
  std::cin >> q;
}
