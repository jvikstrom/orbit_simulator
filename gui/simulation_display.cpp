#include "simulation_display.hpp"

void gui::simulation_display::track(int index, gui::track_settings settings){
  tracked_indexes.push_back(std::pair<int, gui::track_settings>(index, settings));
}

void gui::simulation_display::track(std::string name, gui::track_settings settings){
  tracked_names.push_back(std::pair<std::string, gui::track_settings>(name, settings));
}

vec2 gui::simulation_display::position_to_screenposition(vec2 position){
  return position / divide + vec2(win.get_width(), win.get_height()) / 2;
}

void gui::simulation_display::draw(){
  win.clear();
  for(std::pair<int,track_settings> entry : tracked_indexes){
    object& obj = sim.get(entry.first);
    shape* sh = entry.second.sh;
    if(entry.second.scale){
      //jjstd::cout << obj.name << ", radius::" << sh->size.to_string() << ", " << sh->get_real_size().to_string()<< std::endl;
      /*if(sh->size.x < std::pow(10, 3)){
        std::cout << "Size mutating: " << obj.name << std::endl;
        exit(-1);
      }*/

      sh->size = sh->get_real_size() / divide;
    }
    win.draw(sh, position_to_screenposition(obj.position));
  }
  for(std::pair<std::string, track_settings> entry : tracked_names){
    object& obj = sim.get(entry.first);
    shape* sh = entry.second.sh;
    if(entry.second.scale){
      //std::cout << obj.name << ", radius::" << sh->size.to_string() << ", " << sh->get_real_size().to_string()<<  std::endl;
      /*if(sh->size.x < std::pow(10, 3)){
        std::cout << "Size mutating: " << obj.name << std::endl;
        exit(-1);
      }*/


      sh->size = sh->get_real_size() / divide;
    }

    win.draw(sh, position_to_screenposition(obj.position));
  }
  win.update();
}

void gui::simulation_display::run(){
  int i = 0;
  while(sim.step(i % resolution == 0) < sim.get_end()){
    if(i++ % resolution == 0){
      draw();
    }
  }
}
