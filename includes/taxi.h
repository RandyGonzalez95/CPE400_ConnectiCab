#ifndef TAXI_H
#define TAXI_H

#include <string>

class Taxi {
  friend class Simulation;

  public:
    Taxi();
    ~Taxi();

    // Data member sets
    void setLocationXCoord(char* xCoord);
    void setLocationYCoord(char* yCoord);
    void setDestinationXCoord(char* xCoord);
    void setDestinationYCoord(char* yCoord);
    void setSpeed(char* taxSpeed);

    bool updateLocation(); // Update the location of the taxi based on its speed

  private:
    int locationXCoord;
    int locationYCoord;
    int destinationXCoord;
    int destinationYCoord;
    int speed;
};

#endif // TAXI_H
