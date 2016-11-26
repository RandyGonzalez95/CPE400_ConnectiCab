#ifndef TAXI_H
#define TAXI_H

#include <string>

class Taxi {
  friend class Simulation;

  public:
    Taxi(); // Constructor
    ~Taxi(); // Destructor

    // Data member sets
    void setLocationXCoord(char* xCoord); // Set the location X Coord
    void setLocationYCoord(char* yCoord); // Set the location Y Coord
    void setDestinationXCoord(char* xCoord); // Set the destination X Coord
    void setDestinationYCoord(char* yCoord); // Set the destination Y Coord
    void setSpeed(char* taxSpeed); // Set the speed of the taxi

    bool updateLocation(); // Update the location of the taxi based on its speed

  private:
    int locationXCoord;
    int locationYCoord;
    int destinationXCoord;
    int destinationYCoord;
    int speed;
};

#endif // TAXI_H
