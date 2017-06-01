#pragma once
#include <iostream>
#include <string>
#include <SDL2/SDL.h>

#include "vec2.hpp"
#include "color.hpp"
#include "shape.hpp"

namespace gui{
  /*struct rect{
    unsigned int x, y, w, h;
    rect(vec2 position, vec2 size) : x(position.x), y(position.y), w(size.x), h(size.y){}
    rect(unsigned int x = 0, unsigned int y = 0, unsigned int w = 0, unsigned int h = 0) : x(x), y(y), w(w), h(h){}
  };

  struct circle{
    unsigned int x, y, r;
    circle(unsigned int x, unsigned int y, unsigned int r) : x(x), y(y), r(r){}
    circle(vec2 position, vec2 size) : x(position.x), y(position.y), r(size.x){}
  };*/

  class window{
    SDL_Window* win;
    SDL_Renderer* renderer;
    void setup_sdl();
  public:
    window(){setup_sdl();}
    ~window(){ SDL_DestroyWindow(win); SDL_Quit(); }
    //void drawRect(gui::rect rect, color col);
    //void draw_circle(circle circ, color col);
    void draw(shape* sh, vec2 position = vec2());
    void clear();
    void update();
    double get_width(){ return 512; }
    double get_height(){ return 512; }
  };
}

//namespace gui{}
