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
  mapXSize = atof(xSize);
//  std::cout << "Map X Size: " << mapXSize << std::endl;
}

void Simulation::setMapYSize(char* ySize)
{
  mapYSize = atof(ySize);
//  std::cout << "Map Y Size: " << mapYSize << std::endl;
}

void Simulation::setBluetoothRange(char* btRange)
{
  bluetoothRange = atof(btRange);
//  std::cout << "Bluetooth Range: " << bluetoothRange << std::endl;
}

void Simulation::setWifiRange(char* wfRange)
{
  wifiRange = atof(wfRange);
//  std::cout << "Wifi Range: " << wifiRange << std::endl;
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

float Simulation::calculateDistance(Taxi a, Taxi b)
{
  // Get the difference between the x and y coordinates
  int xLocation = a.locationXCoord - b.locationXCoord;
  int yLocation = a.locationYCoord - b.locationYCoord;

  // Square the x and y and then sqrt in order to find distance using pythagorean theorem
  float calculation = xLocation * xLocation + yLocation * yLocation;
  calculation = sqrt(calculation);

  return calculation;
}

bool Simulation::updateTaxiLocations()
{
  bool movementFlag = false;

  for(unsigned int i = 0; i < taxis.size(); i++)
  {
    if(taxis[i].updateLocation())
    {
      movementFlag = true;
    }
  }

  return movementFlag;
}

void Simulation::updateTaxiBroadcasts()
{
  float distance;

  // Check for taxis to broadcast to
  for(unsigned int i = 0; i < taxis.size(); i++)
  {
    for(unsigned int j = 0; j < taxis.size(); j++)
    {
      if(i == j) // Do nothing as it is the same taxi
      {}

      else // Check if the distance is small enough to start broadcasting
      {
        distance = calculateDistance(taxis[i], taxis[j]);

        if(distance < bluetoothRange)
        {
          std::cout << "Taxi " << i << " is broadcasting bluetooth to Taxi " << j << std::endl << std::endl;
        }

        else if(distance < wifiRange)
        {
          std::cout << "Taxi " << i << " is broadcasting wifi to Taxi " << j << std::endl << std::endl;
        }
      }
    }
  }
}

void Simulation::startSimulation()
{
  bool taxiMovementFlag = true;

  // Keep looping until all taxis reach their destination
  while(taxiMovementFlag)
  {
    // Update all taxis location
    taxiMovementFlag = updateTaxiLocations();

    // Update the taxis each taxi is broadcasting to
    updateTaxiBroadcasts();

  }
}
