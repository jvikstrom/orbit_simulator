#pragma once

#include <vector>
#include <utility>
#include "logger.hpp"
#include "window.hpp"
#include "simulator.hpp"

namespace gui{
  struct track_settings{

  }
  class simulation_display{
    window win;
    std::vector<std::pair<int, track_settings>> tracked_indexes;
    std::vector<std::pair<std::string, track_settings>> tracked_names;
    int resolution = 1;
    simulator sim;
  public:
    simulation_display(int resolution, simulator sim) : resolution(resolution), sim(sim){}
    void track_index(int index, track_settings settings);
    void track_name(std::string name, track_settings settings);
    void run();
  }
}
