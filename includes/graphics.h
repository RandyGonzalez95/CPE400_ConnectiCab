#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "SDL2/SDL.h"

class Graphics {

  public:
    Graphics(int windowXSize, int windowYSize); // Param Constructor
    ~Graphics(); // Destructor

    // Data member gets
    SDL_Renderer* getRenderer(); // Returns the renderer
    SDL_Window* getWindow(); // Returns the window

  private:
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
};

#endif // GRAPHICS_H
