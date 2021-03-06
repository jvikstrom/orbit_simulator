#pragma once

#include "vec2.hpp"

namespace gui{
  class shape{
  protected:
    const vec2 real_size;
  public:
    virtual ~shape(){}
    vec2 size;
    shape(vec2 size = vec2()) : real_size(size), size(size){}
    virtual void draw(vec2 position, SDL_Renderer* renderer) = 0;
    vec2 get_real_size(){return real_size;}
  };
}
