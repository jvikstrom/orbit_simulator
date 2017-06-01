#include <iostream>
#include <cmath>
#include "simulator.hpp"
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

  gui::window win;
  win.drawRect(gui::rect(vec2(250,250), vec2(12,12)));
  int i = 0;
  double p = std::pow(10, 6);
  while(sim.step(i % resolution == 0) < end){
    object& obj = sim.get(1);
    if(i++ % resolution == 0){
      win.drawRect(gui::rect(obj.position / p + vec2(256,256), vec2(5,5)));
    }
  }

  int q;
  std::cin >> q;
}
