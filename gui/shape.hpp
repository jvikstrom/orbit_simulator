#pragma once

#include "vec2.hpp"

namespace gui{
  class shape{
  public:
    virtual void draw(vec2 position, SDL_Renderer* renderer) = 0;
  };
}
