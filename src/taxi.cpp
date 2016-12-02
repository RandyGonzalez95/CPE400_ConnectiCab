#include "taxi.h"

Taxi::Taxi()
{
  packetToTransmit = NULL;
}

Taxi::~Taxi()
{
}

void Taxi::setLocationXCoord(char* xCoord)
{
  locationXCoord = atoi(xCoord);
}

void Taxi::setLocationYCoord(char* yCoord)
{
  locationYCoord = atoi(yCoord);
}

void Taxi::setDestinationXCoord(char* xCoord)
{
  destinationXCoord = atoi(xCoord);
}

void Taxi::setDestinationYCoord(char* yCoord)
{
  destinationYCoord = atoi(yCoord);
}

void Taxi::setSpeed(char* taxSpeed)
{
  speed = atoi(taxSpeed);
}

void Taxi::setPacket(Packet* packet)
{
  packetToTransmit = packet;
}

Packet* Taxi::getPacket()
{
  return packetToTransmit;
}

int Taxi::getLocationXCoord()
{
  return locationXCoord;
}

int Taxi::getLocationYCoord()
{
  return locationYCoord;
}

int Taxi::getSpeed()
{
  return speed;
}

bool Taxi::updateLocation()
{
  // Check if the Taxi is hitting the destination xCoord
  if(locationXCoord < destinationXCoord - speed || locationXCoord > destinationXCoord + speed)
  {
    // If its below the destination move the x coord positive
    if(locationXCoord < destinationXCoord)
    {
      locationXCoord += speed;
    }

    // Else move the x coord negative
    else
    {
      locationXCoord -= speed;
    }
  }

  // Check if the Taxi is hitting the destination yCoord
  else if(locationYCoord < destinationYCoord - speed || locationYCoord > destinationYCoord + speed)
  {
    // If its below the destination move the y coord positive
    if(locationYCoord < destinationYCoord)
    {
      locationYCoord += speed;
    }

    // Else move the y coord negative
    else
    {
      locationYCoord -= speed;
    }
  }

  // If taxi is at its destination stop updating it
  else
  {
    return false;
  }

  return true;
}
