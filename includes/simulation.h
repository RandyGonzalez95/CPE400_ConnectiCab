#ifndef SIMULATION_H
#define SIMULATION_H

#include "taxi.h"
#include "graphics.h"
#include <iostream>
#include <vector>
#include <math.h>
#include <chrono>
#include <thread>

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

    float calculateDistance(Taxi a, Taxi b); // Calculate distance between taxi a and b using pythagorean theorem
    bool updateTaxiLocations(); // Update the taxi location based on its speed
    void updateTaxiBroadcasts(); // Update who the taxis are broadcasting between
    void startSimulation(); // Start the simulation

  private:
    std::vector<Taxi> taxis;
    int mapXSize;
    int mapYSize;
    float bluetoothRange;
    float wifiRange;
};

#endif // SIMULATION_H
