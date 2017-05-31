#include "simulator.hpp"

double simulator::step(double timstep){
  if(t >= t_end){
    return t;
  }
  t += timestep;

  for(int i = 0; i < objects.size(); i++){
    for(int j = i + 1; j < objects.size(); j++){
      vec2 force = objects[i].calcGravityForce(objects[j]);
      objects[i].applyForce(force);
      objects[j].applyForce(-force);
      /*vec2 direction = objects[i].position - objects[j].position;
      double radius = direction.norm();
      double F = G * (objects[i].mass * objects[j].mass) / (radius * radius);
      double a1 = F / objects[i].mass;
      double a2 = F / objects[j].mass;
      //std::cout << F << std::endl;
      //std::cout << direction.to_string() << std::endl;
      direction = direction.normalize();
      objects[i].velocity += direction * a1;
      objects[j].velocity += direction * a2;*/
      //std::cout << direction.to_string() << std::endl;
      //logger::i(objects[i].velocity.to_string(), objects[j].velocity.to_string());
    }
  }

  //std::cout << "timestep: " << timestep << std::endl;
  //std::cout << "t: " <<  t << std::endl;
  logger::i("time", std::to_string(t));
  for(int i = 0; i < objects.size(); i++){
    object &obj = objects[i];
    obj.step(timestep);
    //object& obj = objects[i];
    //obj.position += obj.velocity * timestep;
    logger::i(obj.name, obj.position.to_string());
//    logger::i(obj.name, obj.velocity.to_string());
  }

  return t;
}

double simulator::step(){
  return step(timestep);
}

void simulator::add(object obj){
  objects.push_back(obj);
}
