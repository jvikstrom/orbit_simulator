#include "simulation_display.hpp"

void gui::simulation_display::track_index(int index, gui::track_settings settings){
  tracked_indexes.push_back(std::pair<int, gui::track_settings>(index, settings));
}

void gui::simulation_display::track_name(std::string name, gui::track_settings settings){
  tracked_names.push_back(std::pair<std::string, gui::track_settings>(name, settings));
}
