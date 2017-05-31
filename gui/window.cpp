#include "window.hpp"

void gui::window::setup_sdl(){
  if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
    std::cout << "SDL falied to initialize" << std::endl;
    exit(-1);
  }

  window = SDL_CreateWindow("Simulation", 0, 0, 512, 512, SDL_WINDOW_SHOWN);
  if(window == nullptr){
    std::cout << "SDL could not create window" << std::endl;
    SDL_Quit();
    exit(-1);
  }

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if(renderer == nullptr){
    std::cout << "SDL could not create renderer" << std::endl;
    SDL_Quit();
    exit(-1);
  }
}

void gui::window::drawRect(gui::rect rect){
  struct SDL_Rect sdl_rect;
  sdl_rect.x = rect.x;
  sdl_rect.y = rect.y;
  sdl_rect.w = rect.w;
  sdl_rect.h = rect.h;
  int err;
  if((err = SDL_RenderDrawRect(renderer, &sdl_rect)) != 0){
    throw std::string("Could not draw rect, errorcode: " + std::to_string(err));
  }
}
