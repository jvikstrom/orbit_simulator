#include "simulator.hpp"

double simulator::step(double timstep, bool debug){
  if(t >= t_end){
    return t;
  }
  t += timestep;

  for(int i = 0; i < objects.size(); i++){
    for(int j = i + 1; j < objects.size(); j++){
      vec2 force = objects[i].calcGravityForce(objects[j]);
      objects[i].applyForce(force);
      objects[j].applyForce(-force);
    }
  }

  if(debug){
    logger::i("time", std::to_string(t));
  }

  for(int i = 0; i < objects.size(); i++){
    object &obj = objects[i];
    obj.step(timestep);

    if(debug){
      logger::i(obj.name, obj.position.to_string());
    }
  }

  return t;
}

double simulator::step(bool debug){
  return step(timestep, debug);
}

void simulator::add(object obj){
  objects.push_back(obj);
}
