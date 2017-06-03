#include <iostream>

#include "gtest/gtest.h"
#include "simulator_display.hpp"

class simulator_display_test : public ::testing::Test{
protected:
  virtual void SetUp(){

  }
  virtual void TearDown(){

  }
};

TEST(simulator_display_test, focus_works){
  simulator sim(0, 10, 1);
}
