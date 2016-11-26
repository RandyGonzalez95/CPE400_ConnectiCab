#ifndef SIMULATION_H
#define SIMULATION_H

#include <iostream>
#include "taxi.h"
#include <vector>
#include <math.h>

class Simulation {

  public:
    Simulation(); // Constructor
    ~Simulation(); // Destructor

    // Data member sets
    void setMapXSize(char* xSize); // Set the map's X size
    void setMapYSize(char* ySize); // Set the map's Y size
    void setBluetoothRange(char* btRange); // Set the bluetooth range of the simulation
    void setWifiRange(char* wfRange); // Set the wifi range of the simulation
    void addTaxi(Taxi newTaxi); // Add a taxi to the taxis vector

    void outputTaxis(); // Output all taxis in the taxis vector
    float calculateDistance(Taxi a, Taxi b); // Calculate distance between taxi a and b using pythagorean theorem
    void startSimulation();

  private:
    std::vector<Taxi> taxis;
    int mapXSize;
    int mapYSize;
    float bluetoothRange;
    float wifiRange;
};

#endif // SIMULATION_H
