#include "packet.h"

Packet::Packet()
{

}

Packet::Packet(int source, int destination, int locationXCoord, int locationYCoord, int speed)
{
  sourceTaxi = source;
  destinationTaxi = destination;

  // Create the message
  std::string tempXCoord = std::to_string(locationXCoord);
  std::string tempYCoord = std::to_string(locationYCoord);
  std::string tempSpeed = std::to_string(speed);

  message = "I am going to the desination (" + tempXCoord + ", " +
  tempYCoord + "). At the speed of " + tempSpeed;
};

int Packet::getDestinationTaxi()
{
  return destinationTaxi;
}
