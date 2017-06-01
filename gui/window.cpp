#include "window.hpp"

void gui::window::setup_sdl(){
  if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
    std::cout << "SDL falied to initialize" << std::endl;
    exit(-1);
  }

  win = SDL_CreateWindow("Simulation", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 512, 512, SDL_WINDOW_SHOWN);
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

  SDL_RenderClear(renderer);
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderPresent(renderer);
}

void gui::window::clear(){
  SDL_SetRenderDrawColor(renderer, 0,0,0,255);
  SDL_RenderClear(renderer);
}

void gui::window::update(){
  SDL_RenderPresent(renderer);
}


void gui::window::draw(shape* sh, vec2 position){
  sh->draw(position, renderer);
}
