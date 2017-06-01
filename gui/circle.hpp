#pragma once
#include <iostream>
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
      unsigned int r = size.x;
      std::cout << "Print circle:" << std::endl;
      for(unsigned int x = 0; x < r * 2; x++){
        for(unsigned int y = 0; y < r * 2; y++){
          int dx = r - x, dy = r - y;
          if(dx*dx + dy*dy <= r * r){
            //std::cout << int(position.x + dx) << ", " << int(position.y + dy) << std::endl;
            SDL_RenderDrawPoint(renderer, position.x + dx, position.y + dy);
          }
        }
      }
    }
  };
}
