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

bool Simulation::broadcastMessage(Graphics *graphicInterface, Packet* packet)
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

      // Check if the source taxi has the packet and that the destination packet does not have the packet
      else if(taxis[i].packetToTransmit != NULL && taxis[j].packetToTransmit == NULL)
      {
        // Calculate distance
        distance = calculateDistance(taxis[i], taxis[j]);

        // Check if distance is small enough to reach with bluetooth
        if(distance <= bluetoothRange)
        {
          // Output message of where packet is transmitting
          std::cout << "Packet is broadcast via bluetooth from Taxi " << i << " to Taxi " << j << std::endl;

          // Draw a line between each taxi indicating bluetooth connection
          graphicInterface->drawBluetoothline(taxis[i], taxis[j]);

          // Transmit the message to taxis[j]
          taxis[j].packetToTransmit = packet;

          // Check if that taxi is the destination taxi
          if(packet->destinationTaxi == (int)j)
          {
            return true;
          }
        }

        // Else check if distance is small enough to broadcast with wifi
        else if(distance <= wifiRange)
        {
          // Output message of where packet is transmitting
          std::cout << "Packet is broadcast via wifi from Taxi " << i << " to Taxi " << j << std::endl;

          // Draw a line between each taxi indicating wifi
          graphicInterface->drawWifiLine(taxis[i], taxis[j]);


          // Transmit the message to taxis[j]
          taxis[j].packetToTransmit = packet;

          // Check if that taxis is the destination taxi
          if(packet->destinationTaxi == (int)j)
          {
            return true;
          }
        }
      }
    }
  }

  return false;
}

void Simulation::startSimulation(int sourceTaxi, int destinationTaxi)
{
  // Variables
  bool quit = false;
  bool packetReceived = false;

  // Create the packet that will be transmitted to the destination taxi
  Packet* packet = new Packet(sourceTaxi, destinationTaxi, taxis[destinationTaxi].locationXCoord,
                              taxis[destinationTaxi].locationYCoord, taxis[destinationTaxi].speed);

  // Start the packet at the start taxi
  taxis[sourceTaxi].packetToTransmit = packet;

  // Set up graphic interface
  Graphics *graphicInterface = new Graphics();

  // Keep looping until all taxis reach their destination or packet is received
  while(!quit)
  {

    // Update every 1 second
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // Check for user to quit the program
    quit = graphicInterface->checkForEvents();

    // Draw the buildings and background
    graphicInterface->drawScene();

    if(!packetReceived)
    {
      // Update all taxis location
      taxiMovementFlag = updateTaxiLocations();

      // Broadcast the message to all nearby taxis until destination taxi is found
      if(broadcastMessage(graphicInterface, packet))
      {
        packetReceived = true;
        std::cout << std::endl << "PACKET HAS BEEN RECEIVED" << std::endl;
      }
    }
    // Draw the taxis on the screen
    graphicInterface->drawTaxis(taxis);

    // Render all graphics
    SDL_RenderPresent(graphicInterface->getRenderer());
  }

  delete graphicInterface;
}
