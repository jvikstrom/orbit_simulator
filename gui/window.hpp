#pragma once
#include <iostream>
#include <string>
#include <SDL2/SDL.h>

namespace gui{
  struct rect{
    unsigned int x, y, w, h;
    rect(unsigned int x = 0, unsigned int y = 0, unsigned int w = 0, unsigned int h = 0) : x(x), y(y), w(w), h(h){}
  };

  class window{
    SDL_Window* window;
    SDL_Renderer* renderer;
    void setup_sdl();
  public:

    void drawRect(gui::rect rect);
  };
}

//namespace gui{}
