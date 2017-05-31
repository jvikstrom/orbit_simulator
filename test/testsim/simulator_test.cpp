#include <iostream>

#include "gtest/gtest.h"
#include "simulator.hpp"

class simulator_test : public ::testing::Test{
protected:
  virtual void SetUp(){

  }
  virtual void TearDown(){

  }
};

TEST(simulator_test, can_step){
  simulator sim(0, 1, 0.1);
  ASSERT_FLOAT_EQ(sim.step(), 0.1);
}

TEST(simulator_test, cant_overstep){
  simulator sim(0, 1, 1);
  sim.step();
  ASSERT_FLOAT_EQ(sim.step(), 1);
}

TEST(simulator_test, velocity_applied){
  simulator sim(0, 1, 0.1);
  object small(vec2(), vec2(10, 1), 1);
  sim.add(small);
  sim.step();
  small = sim.get(0);

  vec2 correctPosition(1, 0.1);
  vec2 realPosition = small.position;
  ASSERT_EQ(realPosition, correctPosition);
}

TEST(simulator_test, force_between_objects_applied){
  simulator sim(0, 1, 0.1);
  object small(vec2(1000, 0), vec2(), 1);
  object big(vec2(), vec2(), 1e6);
  sim.add(small);
  sim.add(big);
  sim.step();
  small = sim.get(0);
  ASSERT_GT(small.velocity.norm(), 0);
  ASSERT_GT(small.position.norm(), 0);
}
