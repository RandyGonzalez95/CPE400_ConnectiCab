#include "simulation.h"

Simulation::Simulation()
{
}

Simulation::~Simulation()
{
  // Deallocate memory and remove all taxis
  std::vector<Taxi>().swap(taxis);
}

void Simulation::setMapXSize(char* xSize)
{
  mapXSize = atoi(xSize);
  std::cout << "Map X Size: " << mapXSize << std::endl;
}

void Simulation::setMapYSize(char* ySize)
{
  mapYSize = atoi(ySize);
  std::cout << "Map Y Size: " << mapYSize << std::endl;
}

void Simulation::setMapUnits(char* units)
{
  mapUnits = units;
  std::cout << "Map Units: " << mapUnits << std::endl;
}

void Simulation::setBluetoothRange(char* btRange)
{
  bluetoothRange = atof(btRange);
  std::cout << "Bluetooth Range: " << bluetoothRange << std::endl;
}

void Simulation::setWifiRange(char* wfRange)
{
  wifiRange = atof(wfRange);
  std::cout << "Wifi Range: " << wifiRange << std::endl;
}

void Simulation::addTaxi(Taxi newTaxi)
{
  taxis.push_back(newTaxi);
}

void Simulation::outputTaxis()
{
  for(unsigned int i = 0; i < taxis.size(); i++)
  {
    std::cout << "TAXI " << i << " INFO:" << std::endl;
    std::cout << "Location X Coord: " << taxis[i].locationXCoord << std::endl;
    std::cout << "Location Y Coord: " << taxis[i].locationYCoord << std::endl;
    std::cout << "Destination X Coord: " << taxis[i].destinationXCoord << std::endl;
    std::cout << "Destination Y Coord: " << taxis[i].destinationYCoord << std::endl;
    std::cout << "Speed: " << taxis[i].speed << std::endl;
  }
}

bool Simulation::generateGraph()
{

}
