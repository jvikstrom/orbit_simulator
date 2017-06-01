#include <iostream>
#include "simulator.hpp"
#include "object.hpp"
#include "window.hpp"

int main(){
  double end = 20000;
  simulator sim(0, end, 10);
  object earth(vec2(0,0), vec2(0,0), 5000000);
  earth.name = "earth";
  object obj(vec2(100, 0), vec2(0, -10000/3600), 10);
  obj.name = "rocket";
  sim.add(earth);
  sim.add(obj);

  gui::window win;
  win.drawRect(gui::rect(vec2(250,250), vec2(12,12)));
  int i = 0;
  while(sim.step() < end){
    object& obj = sim.get(1);
    if(i % 10 == 0)
      win.drawRect(gui::rect(obj.position / 100 + vec2(256,256), vec2(5,5)));
      i++;
    //win.drawRect(gui::rect(obj.position.x/100 + 256, obj.position.y/100 + 256, 10, 10));
  }

  int q;
  std::cin >> q;
}
