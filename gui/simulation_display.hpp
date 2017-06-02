#pragma once

#include <vector>
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
    track_settings(shape * sh, bool scale = true) : scale(scale), sh(sh){}
  };
  class simulation_display{
    window win;
    std::vector<std::pair<int, track_settings>> tracked_indexes;
    std::vector<std::pair<std::string, track_settings>> tracked_names;
    int resolution = 1;
    double divide = 1;
    simulator sim;
    vec2 position_to_screenposition(vec2 position);
    void draw();
  public:
    simulation_display(int resolution, double divide, simulator sim) : resolution(resolution), divide(divide), sim(sim){}
    void track(int index, track_settings settings);
    void track(std::string name, track_settings settings);
    void run();
  };
}
