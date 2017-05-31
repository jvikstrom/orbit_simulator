#include <iostream>
#include <cmath>

#include "gtest/gtest.h"
#include "object.hpp"

double epsilon = 1e-10;

class object_test : public ::testing::Test{
protected:
  virtual void SetUp(){

  }
  virtual void TearDown(){

  }
};

TEST(object_test, force_calc_correct){
  object small(vec2(10, 0), vec2(), 10);
  object big(vec2(), vec2(), 10000);
  vec2 force = small.calcGravityForce(big);
  double G = 6.674 * std::pow(10, -11);
  vec2 correctForce = vec2(-G*small.mass*big.mass/(std::pow((small.position-big.position).norm(), 2)), 0);
  ASSERT_EQ(force, correctForce);
  force = big.calcGravityForce(small);
  correctForce.x *= -1;
  ASSERT_EQ(force, correctForce);
}

TEST(object_test, force_apply_test){
  object obj(vec2(), vec2(), 2);
  vec2 f(10, 1);
  obj.applyForce(f);
  vec2 correctVelocity(5, 0.5);
  ASSERT_EQ(obj.velocity, correctVelocity);
}

TEST(object_test, step_test){
  object obj(vec2(), vec2(10, 100), 101);
  obj.step(0.1);
  vec2 correctPosition(1, 10);
  ASSERT_EQ(obj.position, correctPosition);
}
