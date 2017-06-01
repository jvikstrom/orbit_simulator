#pragma once
#include <iostream>
#include <string>
#include <SDL2/SDL.h>

#include "vec2.hpp"
#include "color.hpp"
#include "shape.hpp"

namespace gui{
  class window{
    SDL_Window* win;
    SDL_Renderer* renderer;
    void setup_sdl();
  public:
    window(){setup_sdl();}
    ~window(){ SDL_DestroyWindow(win); SDL_Quit(); }
    void draw(shape* sh, vec2 position = vec2());
    void clear();
    void update();
    double get_width(){ return 512; }
    double get_height(){ return 512; }
  };
}
