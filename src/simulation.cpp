#include "simulation.h"

Simulation::Simulation()
{
}

Simulation::~Simulation()
{
  // Deallocate memory and remove all taxis
  std::vector<Taxi>().swap(taxis);
}

void Simulation::setBluetoothRange(char* btRange)
{
  bluetoothRange = atof(btRange);
}

void Simulation::setWifiRange(char* wfRange)
{
  wifiRange = atof(wfRange);
}

void Simulation::addTaxi(Taxi newTaxi)
{
  taxis.push_back(newTaxi);
}

float Simulation::calculateDistance(Taxi a, Taxi b)
{
  // Get the difference between the x and y coordinates
  int xLocation = a.locationXCoord - b.locationXCoord;
  int yLocation = a.locationYCoord - b.locationYCoord;

  // Square the x and y and then sqrt the sum in order to find distance using pythagorean theorem
  float calculation = xLocation * xLocation + yLocation * yLocation;
  calculation = sqrt(calculation);

  return calculation;
}

bool Simulation::updateTaxiLocations()
{
  // Variables
  bool movementFlag = false;

  // Go through all taxis and update their location
  for(unsigned int i = 0; i < taxis.size(); i++)
  {
    // Check if the taxi was updated, if it was updated set the movement flag
    if(taxis[i].updateLocation())
    {
      movementFlag = true;
    }
  }

  return movementFlag;
}

void Simulation::updateTaxiBroadcasts(Graphics *graphicInterface)
{
  // Variables
  float distance;

  // Need to check each taxi with every other taxi to determine if they are in range
  for(unsigned int i = 0; i < taxis.size(); i++)
  {
    for(unsigned int j = 0; j < taxis.size(); j++)
    {
      if(i == j) // Do nothing as it is the same taxi
      {}

      else // Check if the distance is small enough to start broadcasting
      {
        // Calculate distance
        distance = calculateDistance(taxis[i], taxis[j]);

        // Check if distance is small enough to reach with bluetooth
        if(distance <= bluetoothRange)
        {
          std::cout << "Taxi " << i << " is broadcasting bluetooth to Taxi " << j << std::endl << std::endl;
          SDL_SetRenderDrawColor(graphicInterface->getRenderer(), 0, 200, 0, 255);
          SDL_RenderDrawLine(graphicInterface->getRenderer(), taxis[i].locationXCoord, taxis[i].locationYCoord, taxis[j].locationXCoord, taxis[j].locationYCoord);
        }

        // Else check if distance is small enough to broadcast with wifi
        else if(distance <= wifiRange)
        {
          std::cout << "Taxi " << i << " is broadcasting wifi to Taxi " << j << std::endl << std::endl;
          SDL_SetRenderDrawColor(graphicInterface->getRenderer(), 0, 0, 200, 255);
          SDL_RenderDrawLine(graphicInterface->getRenderer(), taxis[i].locationXCoord, taxis[i].locationYCoord, taxis[j].locationXCoord, taxis[j].locationYCoord);
        }
      }
    }
  }
}

void Simulation::startSimulation()
{
  // Variables
  bool taxiMovementFlag = true;
  bool quit = false;

  // Set up graphic interface
  Graphics *graphicInterface = new Graphics();

  // Keep looping until all taxis reach their destination
  while(taxiMovementFlag && !quit)
  {
    // Update every 1 second
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // Check for user to quit the program
    quit = graphicInterface->checkForEvents();

    // Draw the buildings and background
    graphicInterface->drawScene();

    // Update all taxis location
    taxiMovementFlag = updateTaxiLocations();

    // Update the taxis each taxi is broadcasting to
    updateTaxiBroadcasts(graphicInterface);


    // Draw the taxis on the screen
    graphicInterface->drawTaxis(taxis);

    // Render all graphics
    SDL_RenderPresent(graphicInterface->getRenderer());
  }

  delete graphicInterface;
}
