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
  speed = atof(taxSpeed);
}
