#pragma once

#include <string>
#include <cmath>
#include <iostream>

struct vec2{
  double x, y;
  vec2(double x = 0, double y = 0) : x(x), y(y){}

  double norm(){
    return std::sqrt(x*x + y*y);
  }

  vec2 normalize(){
    double norm = this->norm();
    if(norm == 0)
      norm = 1;
    return vec2(x / norm, y / norm);
  }

  std::string to_string(){
    return std::string("{") + std::to_string(x) + std::string(", ") + std::to_string(y) + std::string("}");
  }

  vec2& operator+=(const vec2& rhs){
    x += rhs.x;
    y += rhs.y;
    return *this;
  }

  vec2& operator-=(const vec2& rhs){
    x -= rhs.x;
    y -= rhs.y;
    return *this;
  }

  vec2& operator*=(double v){
    x *= v;
    y *= v;
    return *this;
  }

  bool operator==(vec2& rhs){
    double epsilon = 1e-10;
    return std::abs(x - rhs.x) < epsilon &&  std::abs(y - rhs.y) < epsilon;
  }

  bool operator==(const vec2& rhs) const{
    double epsilon = 1e-10;
    return std::abs(x - rhs.x) < epsilon &&  std::abs(y - rhs.y) < epsilon;
  }

  vec2& operator/=(double d){
    x /= d;
    y /= d;
    return *this;
  }

  friend vec2 operator+(vec2 lhs, const vec2& rhs){
    lhs += rhs;
    return lhs;
  }

  friend vec2 operator-(vec2 lhs, const vec2& rhs){
    lhs -= rhs;
    return lhs;
  }

  //Might require a const version
  friend vec2 operator-(vec2 lhs){
    lhs *= -1;
    return lhs;
  }

  friend vec2 operator*(vec2 lhs, double v){
    lhs *= v;
    return lhs;
  }

  friend vec2 operator*(double v, vec2 rhs){
    rhs *= v;
    return rhs;
  }

  friend vec2 operator/(vec2 lhs, double v){
    lhs *= 1 / v;
    return lhs;
  }
};
