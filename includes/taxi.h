#ifndef TAXI_H
#define TAXI_H

#include <string>

class Taxi {
  friend class Simulation;

  public:
    Taxi();
    ~Taxi();
    void setLocationXCoord(char* xCoord);
    void setLocationYCoord(char* yCoord);
    void setDestinationXCoord(char* xCoord);
    void setDestinationYCoord(char* yCoord);
    void setSpeed(char* taxSpeed);

  private:
    int locationXCoord;
    int locationYCoord;
    int destinationXCoord;
    int destinationYCoord;
    double speed;
};

#endif // TAXI_H
