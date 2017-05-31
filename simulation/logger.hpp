#pragma once
#include <iostream>
#include <string>

class logger{
public:
  static void i(std::string tag, std::string msg){
    std::cout << tag << "::" << msg << std::endl;
  }
};
