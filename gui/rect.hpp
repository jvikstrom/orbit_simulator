#pragma once
#include <SDL2/SDL.h>
#include "shape.hpp"
#include "vec2.hpp"
#include "color.hpp"

namespace gui{
  class rect : public shape{
    vec2 size;
    color col;
  public:
    rect(vec2 size = vec2(2,2), color col = color()) : size(size), col(col){}
    virtual void draw(vec2 position, SDL_Renderer* renderer){
      struct SDL_Rect sdl_rect;
      sdl_rect.x = position.x;
      sdl_rect.y = position.y;
      sdl_rect.w = size.x;
      sdl_rect.h = size.y;
      int err;
      SDL_SetRenderDrawColor(renderer, col.r, col.g, col.b, 255);
      if((err = SDL_RenderDrawRect(renderer, &sdl_rect)) != 0){
        throw std::string("Could not draw rect, errorcode: " + std::to_string(err));
      }
    }
  };
}
