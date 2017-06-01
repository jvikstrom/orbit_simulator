#pragma once
#include "shape.hpp"
#include "color.hpp"
#include "vec2.hpp"

namespace gui{
  class circle : public shape{
    vec2 size;
    color col;
  public:
    circle(vec2 size = vec2(2,2), color col = color()) : size(size), col(col){}
    virtual void draw(vec2 position, SDL_Renderer* renderer){
      SDL_SetRenderDrawColor(renderer, col.r, col.g, col.b, 255);
      for(unsigned int x = 0; x < size.x * 2; x++){
        for(unsigned int y = 0; y < size.y * 2; y++){
          unsigned int dx = size.x - x, dy = size.y - y;
          if(dx*dx + dy*dy <= size.x * size.y){
            SDL_RenderDrawPoint(renderer, position.x + dx, position.y + dy);
          }
        }
      }
    }
  };
}
