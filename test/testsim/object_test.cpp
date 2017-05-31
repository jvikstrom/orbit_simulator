#include "gtest/gtest.h"
#include "object.hpp"
#include <cmath>
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
  vec2 force = small.calcForce(big);
  double G = 6.674 * std::pow(10, -11);
  vec2 correctForce = vec2(-G*small.mass*big.mass/(std::pow((small.position-big.position).norm(), 2)), 0);
  ASSERT_EQ(force, correctForce);
  force = big.calcForce(small);
  correctForce.x *= -1;
  ASSERT_EQ(force, correctForce);
}

TEST(object_test, construct_works){
  object obj;
  ASSERT_FLOAT_EQ(obj.position.x, vec2().x);
}
