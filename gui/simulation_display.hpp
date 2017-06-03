#pragma once

#include <vector>
#include <map>
#include <utility>

#include "logger.hpp"
#include "window.hpp"
#include "simulator.hpp"
#include "color.hpp"
#include "rect.hpp"
#include "circle.hpp"

namespace gui{
  struct track_settings{
    bool scale = false;
    shape* sh;
    double zoom = 1;
    track_settings(shape * sh = nullptr, bool scale = true, double zoom = 1) : scale(scale), sh(sh), zoom(zoom){}
  };

  class simulation_display{
    window win;
    std::vector<std::pair<int, track_settings>> tracked_indexes;
    std::map<std::string, track_settings> tracked_names;
    int resolution = 1;
    double divide = 1;
    simulator sim;
    std::string focus_name;

    vec2 position_to_screenposition(vec2 position);
    void draw();
  public:
    simulation_display(int resolution, double divide, simulator sim) : resolution(resolution), divide(divide), sim(sim){}
    void track(int index, track_settings settings);
    void track(std::string name, track_settings settings);
    void focus(std::string name);
    void run();
  };
}
