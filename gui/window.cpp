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

/*void gui::window::draw_circle(gui::circle circ, gui::color col){
  SDL_SetRenderDrawColor(renderer, col.r, col.g, col.b, 255);
  for(unsigned int x = 0; x < circ.r * 2; x++){
    for(unsigned int y = 0; y < circ.y * 2; y++){
      unsigned int dx = circ.r - x, dy = circ.r - y;
      if(dx*dx + dy*dy <= circ.r * circ.r){
        SDL_RenderDrawPoint(renderer, circ.x + dx, circ.y + dy);
      }
    }
  }
}

void gui::window::drawRect(gui::rect rect, color col){
  struct SDL_Rect sdl_rect;
  sdl_rect.x = rect.x;
  sdl_rect.y = rect.y;
  sdl_rect.w = rect.w;
  sdl_rect.h = rect.h;
  int err;
  SDL_SetRenderDrawColor(renderer, col.r, col.g, col.b, 255);
  if((err = SDL_RenderDrawRect(renderer, &sdl_rect)) != 0){
    throw std::string("Could not draw rect, errorcode: " + std::to_string(err));
  }
  //SDL_RenderPresent(renderer);
}
*/
