#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "SDL2/SDL.h"
#include <vector>
#include "taxi.h"

class Graphics {

  public:
    Graphics(); // Constructor
    ~Graphics(); // Destructor

    // Data member gets
    SDL_Renderer* getRenderer(); // Returns the renderer
    SDL_Window* getWindow(); // Returns the window
    void drawScene(); // Draw the buildings
    bool checkForEvents();
    void drawTaxis(std::vector<Taxi> taxis);

  private:
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
};

#endif // GRAPHICS_H
