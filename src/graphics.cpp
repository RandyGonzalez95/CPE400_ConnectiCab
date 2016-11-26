#include "graphics.h"

Graphics::Graphics(int windowXSize, int windowYSize)
{
  SDL_Init(SDL_INIT_VIDEO);

  window = SDL_CreateWindow("ConnectiCab", 100, 100, windowXSize, windowYSize, 0);

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Renderer* Graphics::getRenderer()
{
  return renderer;
}

SDL_Window* Graphics::getWindow()
{
  return window;
}
