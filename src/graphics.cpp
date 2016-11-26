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

void Graphics::drawScene(int windowXSize, int windowYSize)
{
  int test = windowXSize * 0.25;
  int test2 = windowYSize * 0.25;

  SDL_Rect drawRect = {test - 20, test2 - 20, 70 * 10, 70 * 5};
  SDL_SetRenderDrawColor(renderer, 84, 84, 84, 255);
  SDL_RenderDrawRect(renderer, &drawRect);

  for(int i = 0; i < 5; i++)
  {
    for(int j = 0; j < 10; j++)
    {
      SDL_Rect fillRect = {test, test2, 20, 30};
      SDL_SetRenderDrawColor(renderer, 84, 84, 84, 255);
      SDL_RenderFillRect(renderer, &fillRect);
      test += 70;
    }
    test = windowXSize * 0.25;
    test2 += 70;
  }
}
