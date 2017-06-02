#pragma once
#include <iostream>
#include "shape.hpp"
#include "color.hpp"
#include "vec2.hpp"

namespace gui{
  class circle : public shape{
    color col;
  public:
    circle(vec2 size = vec2(2,2), color col = color()) : shape(size), col(col){}
    virtual void draw(vec2 position, SDL_Renderer* renderer){
      position += size / 2;
      SDL_SetRenderDrawColor(renderer, col.r, col.g, col.b, 255);
      int r = size.x;
      for(int x = 0; x < r * 2; x++){
        for(int y = 0; y < r * 2; y++){
          int dx = r - x, dy = r - y;
          if(dx*dx + dy*dy <= r * r){
            SDL_RenderDrawPoint(renderer, position.x + dx, position.y + dy);
          }
        }
      }
    }
  };
}
