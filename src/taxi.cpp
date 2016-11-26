#include "taxi.h"

Taxi::Taxi()
{
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

bool Taxi::updateLocation()
{
  // Move the taxi to the correct x Coord first
  if(locationXCoord < destinationXCoord - speed || locationXCoord > destinationXCoord + speed)
  {
    if(locationXCoord < destinationXCoord)
    {
      locationXCoord += speed;
    }

    else
    {
      locationXCoord -= speed;
    }
  }

  // Then move it to the correct y Coord
  else if(locationYCoord < destinationYCoord - speed || locationYCoord > destinationYCoord + speed)
  {
    if(locationYCoord < destinationYCoord)
    {
      locationYCoord += speed;
    }

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
