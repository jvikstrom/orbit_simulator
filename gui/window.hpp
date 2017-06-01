#pragma once
#include <iostream>
#include <string>
#include <SDL2/SDL.h>

#include "vec2.hpp"

namespace gui{
  struct rect{
    unsigned int x, y, w, h;
    rect(vec2 position, vec2 size) : x(position.x), y(position.y), w(size.x), h(size.y){}
    rect(unsigned int x = 0, unsigned int y = 0, unsigned int w = 0, unsigned int h = 0) : x(x), y(y), w(w), h(h){}
  };

  class window{
    SDL_Window* win;
    SDL_Renderer* renderer;
    void setup_sdl();
  public:
    window(){setup_sdl();}
    ~window(){ SDL_DestroyWindow(win); SDL_Quit(); }
    void drawRect(gui::rect rect);
  };
}

//namespace gui{}
