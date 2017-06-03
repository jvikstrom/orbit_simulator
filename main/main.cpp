#include <iostream>
#include <cmath>
#include "simulator.hpp"
#include "simulation_display.hpp"
#include "object.hpp"
#include "window.hpp"
#include "color.hpp"
#include "circle.hpp"
#include "rect.hpp"

void add_sol_system(simulator& sim);
int main(){
  int resolution = 10000;
  double timestep = 1;
  double size_increase_fac = 1;
  double size = /*std::pow(10, 9)*/ std::pow(10, 7) / 4;
  double end = 50*365*24*3600;
  double earth_radius = /*10 * */size_increase_fac * 6.371 * std::pow(10, 6);
  double moon_radius = 2 * size_increase_fac * 1.737 * std::pow(10, 6);
  double sun_radius = size_increase_fac * 6.963 * std::pow(10,8);

  simulator sim(0, end, timestep);
  add_sol_system(sim);

  gui::simulation_display disp(resolution, size, sim);
  gui::shape* earth_rend = new gui::circle(vec2(earth_radius,earth_radius), gui::color(0,0,255));
  gui::shape* moon_rend = new gui::circle(vec2(moon_radius,moon_radius), gui::color(255,255,255));
  gui::shape* rocket_rend = new gui::rect(vec2(5,5), gui::color(255,255,255));
  gui::shape* sun_rend = new gui::circle(vec2(sun_radius,sun_radius), gui::color(255,0,0));
  disp.track("sun", gui::track_settings(sun_rend, true, std::pow(10, 9)));
  disp.track("moon", gui::track_settings(moon_rend, true, std::pow(10, 6)));
  disp.track("earth", gui::track_settings(earth_rend, true,std::pow(10, 7) / 4));
  disp.track("rocket", gui::track_settings(rocket_rend, false, std::pow(10, 6)));
  disp.focus("earth");
  disp.run();

  delete earth_rend;
  delete moon_rend;
  delete rocket_rend;
  int q;
  std::cin >> q;
}

void add_sol_system(simulator& sim){
  //
  vec2 earth_orbit_speed(0, 3 * std::pow(10, 4));
  vec2 moon_orbit_speed =  vec2(0, 1.022*std::pow(10, 3)) + earth_orbit_speed;
  vec2 rocket_orbit_speed = vec2(0, 3.07 * 1000) + earth_orbit_speed;
  object earth(vec2(0,0), earth_orbit_speed, 5.972 * std::pow(10,24));
  earth.name = "earth";
  object moon(vec2(384.4*std::pow(10, 6)), moon_orbit_speed, 7.342 * std::pow(10, 22));
  moon.name = "moon";
  object obj(vec2(36 * std::pow(10, 6), 0), rocket_orbit_speed, 10);
  obj.name = "rocket";
  object sun(vec2(1.496 * std::pow(10, 11), 0), vec2(0,0), 1.989*std::pow(10, 31));
  sun.name = "sun";
  sim.add(sun);
  sim.add(earth);
  sim.add(moon);
  sim.add(obj);
}
