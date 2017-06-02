#include <iostream>
#include <cmath>
#include "simulator.hpp"
#include "simulation_display.hpp"
#include "object.hpp"
#include "window.hpp"
#include "color.hpp"
#include "circle.hpp"
#include "rect.hpp"
//TODO: Make the "models" be scaled with the size variable as well.
int main(){
  int resolution = 1000;
  double size = std::pow(10, 7) / 4;
  double end = 365*24*3600;
  double earth_radius = 6.371 * std::pow(10, 6);
  double moon_radius = 1.737 * std::pow(10, 6);
  double sun_radius = 6.963 * std::pow(10,8);

  simulator sim(0, end, 1);
  object earth(vec2(0,0), vec2(0,0), 5.972 * std::pow(10,24));
  earth.name = "earth";
  object moon(vec2(384*std::pow(10, 6)), vec2(0, 1.022*std::pow(10, 3)), 7.342 * std::pow(10, 22));
  moon.name = "moon";
  object obj(vec2(36 * std::pow(10, 6), 0), vec2(0, 3.07 * 1000), 10);
  obj.name = "rocket";
  object sun(vec2(-1.44 * std::pow(10, 11), 0), vec2(0,0), 1.989*std::pow(10, 30));
  sun.name = "sun";
  sim.add(sun);
  sim.add(earth);
  sim.add(moon);
  sim.add(obj);

  gui::simulation_display disp(resolution, size, sim);
  gui::shape* earth_rend = new gui::circle(vec2(earth_radius,earth_radius), gui::color(0,0,255));
  gui::shape* moon_rend = new gui::circle(vec2(moon_radius,moon_radius), gui::color(255,255,255));
  gui::shape* rocket_rend = new gui::rect(vec2(5,5), gui::color(255,255,255));
  disp.track("earth", gui::track_settings(earth_rend, true));
  disp.track("rocket", gui::track_settings(rocket_rend, false));
  disp.track("moon", gui::track_settings(moon_rend, true));
  disp.run();

  delete earth_rend;
  delete moon_rend;
  delete rocket_rend;
  int q;
  std::cin >> q;
}
