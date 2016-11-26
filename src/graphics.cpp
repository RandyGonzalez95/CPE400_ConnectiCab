#include "graphics.h"

Graphics::Graphics(int windowXSize, int windowYSize)
{
  // Initialize SDL
  SDL_Init(SDL_INIT_VIDEO);

  // Create the window
  window = SDL_CreateWindow("ConnectiCab", 100, 100, windowXSize, windowYSize, 0);

  // Create the renderer
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

Graphics::~Graphics()
{
  // Destroy renderer and window
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
}

SDL_Renderer* Graphics::getRenderer()
{
  return renderer;
}

SDL_Window* Graphics::getWindow()
{
  return window;
}
