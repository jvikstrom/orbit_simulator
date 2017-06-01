#include "window.hpp"

void gui::window::setup_sdl(){
  if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
    std::cout << "SDL falied to initialize" << std::endl;
    exit(-1);
  }

  win = SDL_CreateWindow("Simulation", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 512, 512, SDL_WINDOW_SHOWN);
  std::cout << "Create window" << std::endl;
  if(win == nullptr){
    std::cout << "SDL could not create window" << std::endl;
    SDL_Quit();
    exit(-1);
  }

  renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if(renderer == nullptr){
    std::cout << "SDL could not create renderer" << std::endl;
    SDL_Quit();
    exit(-1);
  }

  //SDL_Delay(100);
  SDL_RenderClear(renderer);
  SDL_SetRenderDrawColor(renderer, 200, 0, 0, 255);
  //SDL_RenderFillRect(renderer, NULL);
  //drawRect(gui::rect(200,200, 50,50));
  SDL_RenderPresent(renderer);
  //SDL_Delay(2500);
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
  SDL_RenderPresent(renderer);
}
