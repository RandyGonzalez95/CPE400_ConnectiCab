#ifndef SIMULATION_H
#define SIMULATION_H

#include "graphics.h"
#include <iostream>
#include <math.h>
#include <chrono>
#include <thread>

class Simulation {

  public:
    Simulation(); // Constructor
    ~Simulation(); // Destructor

    // Data member sets
    void setBluetoothRange(char* btRange); // Set the bluetooth range of the simulation
    void setWifiRange(char* wfRange); // Set the wifi range of the simulation
    void addTaxi(Taxi newTaxi); // Add a taxi to the taxis vector

    float calculateDistance(Taxi a, Taxi b); // Calculate distance between taxi a and b using pythagorean theorem
    bool updateTaxiLocations(); // Update the taxi location based on its speed
    bool broadcastMessage(Graphics *graphicInterface, Packet* packet); // Broadcast the message to all nearby taxis
    void startSimulation(); // Start the simulation

  private:
    std::vector<Taxi> taxis;
    float bluetoothRange;
    float wifiRange;
};

#endif // SIMULATION_H
