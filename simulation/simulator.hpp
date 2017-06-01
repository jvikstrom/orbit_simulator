#pragma once
#include <iostream>
#include <vector>
#include <cmath>

#include "logger.hpp"
#include "object.hpp"
#include "vec2.hpp"

class simulator{
  const double G = 6.674 * std::pow(10, -11);
  double timestep = 1;
  double t_start = 0;
  double t_end = 0;
  double t;
  std::vector<object> objects;

public:
  simulator(double t_start, double t_end, double timestep) : timestep(timestep), t_start(t_start), t_end(t_end){
    t = t_start;
  }
  double step(bool debug = false);
  double step(double timestep, bool debug = false);

  void add(object obj);

  object& get(std::size_t i){
    return objects[i];
  }
  object& get(std::string name){
    for(int i = 0; i < objects.size(); i++){
      if(objects[i].name == name){
        return objects[i];
      }
    }
    throw std::string("Couldn't find object with name: " + name);
  }

  double getEnd(){
    return t_end;
  }
};
