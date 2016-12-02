#include "graphics.h"

Graphics::Graphics()
{
  // Initialize SDL
  SDL_Init(SDL_INIT_VIDEO);

  // Create the window
  window = SDL_CreateWindow("ConnectiCab", 100, 100, 1280, 720, 0);

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

void Graphics::drawScene()
{
  int xVal = 320;
  int yVal = 180;

  // Clear screen with background color
  SDL_SetRenderDrawColor(renderer, 147, 147, 147, 255);
  SDL_RenderClear(renderer);

  // Draw rectangle around city
  SDL_Rect drawRect = {xVal, yVal, 650, 310};
  SDL_SetRenderDrawColor(renderer, 84, 84, 84, 255);
  SDL_RenderDrawRect(renderer, &drawRect);

  // Create all of the buildings on the screen
  for(int i = 0; i < 5; i++)
  {
    for(int j = 0; j < 10; j++)
    {
      SDL_Rect fillRect = {xVal, yVal, 20, 30};
      SDL_SetRenderDrawColor(renderer, 84, 84, 84, 255);
      SDL_RenderFillRect(renderer, &fillRect);
      xVal += 70;
    }

    xVal = 320;
    yVal += 70;
  }
}

bool Graphics::checkForEvents()
{
  SDL_Event m_event;

  // Check through queue of SDL events for a quit
  while(SDL_PollEvent(&m_event) != 0)
  {
    // If user hits 'x' in top right quit program
    if(m_event.type == SDL_QUIT)
    {
      return true;
    }

    else if (m_event.type == SDL_KEYDOWN)
    {
      // If escape key is pressed quit program
      if (m_event.key.keysym.sym == SDLK_ESCAPE)
      {
        return true;
      }
    }
  }

  return false;
}

void Graphics::drawTaxis(std::vector<Taxi> taxis)
{
  // Go through each taxi in the list
  for(unsigned int i = 0; i < taxis.size(); i++)
  {
    // If the taxi has the packet make the taxi red
    if(taxis[i].getPacket() != NULL)
    {
      SDL_Rect drawRect = {taxis[i].getLocationXCoord(), taxis[i].getLocationYCoord(), 17, 15};
      SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
      SDL_RenderFillRect(renderer, &drawRect);
    }

    // Else make the taxi yellow
    else
    {
      SDL_Rect drawRect = {taxis[i].getLocationXCoord(), taxis[i].getLocationYCoord(), 17, 15};
      SDL_SetRenderDrawColor(renderer, 229, 229, 0, 255);
      SDL_RenderFillRect(renderer, &drawRect);
    }
  }
}

void Graphics::drawBluetoothline(Taxi a, Taxi b)
{
  SDL_SetRenderDrawColor(renderer, 0, 200, 0, 255);
  SDL_RenderDrawLine(renderer, a.getLocationXCoord(), a.getLocationYCoord(), b.getLocationXCoord(), b.getLocationYCoord());
}

void Graphics::drawWifiLine(Taxi a, Taxi b)
{
  SDL_SetRenderDrawColor(renderer, 0, 0, 200, 255);
  SDL_RenderDrawLine(renderer, a.getLocationXCoord(), a.getLocationYCoord(), b.getLocationXCoord(), b.getLocationYCoord());
}
