#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "taxi.h"
#include "SDL2/SDL.h"
#include <vector>

class Graphics {

  public:
    Graphics(); // Constructor
    ~Graphics(); // Destructor

    // Data member gets
    SDL_Renderer* getRenderer(); // Returns the renderer
    SDL_Window* getWindow(); // Returns the window
    void drawScene(); // Draw the buildings
    bool checkForEvents(); // Check for graphics events
    void drawTaxis(std::vector<Taxi> taxis); // Draw the taxis
    void drawBluetoothline(Taxi a, Taxi b); // Draw bluetooth line between two taxis
    void drawWifiLine(Taxi a, Taxi b); // Draw wifi line between two taxis

  private:
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
};

#endif // GRAPHICS_H
