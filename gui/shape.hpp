#pragma once

#include "vec2.hpp"

namespace gui{
  class shape{
  protected:
    vec2 size;
  public:
    shape(vec2 size = vec2()) : size(size){}
    virtual void draw(vec2 position, SDL_Renderer* renderer) = 0;
  };
}
