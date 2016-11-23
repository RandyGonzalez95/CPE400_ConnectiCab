#ifndef SIMULATION_H
#define SIMULATION_H

#include "taxi.h"
#include <vector>
#include <iostream>

class Simulation {

  public:
    Simulation();
    ~Simulation();
    void setMapXSize(char* xSize);
    void setMapYSize(char* ySize);
    void setMapUnits(char* units);
    void setBluetoothRange(char* btRange);
    void setWifiRange(char* wfRange);
    void addTaxi(Taxi newTaxi);
    void outputTaxis();

  private:
    std::vector<Taxi> taxis;
    int mapXSize;
    int mapYSize;
    char* mapUnits;
    double bluetoothRange;
    double wifiRange;
};

#endif // SIMULATION_H
