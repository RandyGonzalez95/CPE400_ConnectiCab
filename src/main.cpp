#include <fstream>
#include <iostream>
#include <vector>
#include "taxi.h"
#include "rapidxml-1.13/rapidxml.hpp"

using namespace std;
using namespace rapidxml;

struct MetaData {
  char* mapXSize;
  char* mapYSize;
  char* units;
  char* bluetoothRange;
  char* wifiRange;
};

/* Reads in all data from the given XML configFile. */
bool readIn(MetaData &metaData, vector<Taxi> &taxis);

int main()
{
  // Variables
  vector<Taxi> taxis;
  MetaData metaData;

  // Read in data from XML config file
  if(!readIn(metaData, taxis))
  {
    cout << "ERROR: Error in reading in XML file\n";
    return 0;
  }

  return 0;
}

bool readIn(MetaData &metaData, vector<Taxi> &taxis)
{
  // Variables
  xml_document<> doc;
  xml_node<> *root_node;

  // Open XML File
  ifstream configFile ("../assets/configFile.xml");
  if(!configFile)
  {
    cout << "ERROR: Config File not found\n";
    return false;
  }

  // Read the XML file into a vector
  vector<char> buffer((istreambuf_iterator<char>(configFile)), istreambuf_iterator<char>());
  buffer.push_back('\0');

  // Parse the buffer into doc
  doc.parse<0>(&buffer[0]);

  // Get root node
  root_node = doc.first_node("ConnectiCab");

  // Get Map Size and units used
  root_node = root_node->first_node("MapSize");
  metaData.units = root_node->first_attribute("units")->value();
  metaData.mapXSize = root_node->first_attribute("xSize")->value();
  metaData.mapYSize = root_node->first_attribute("ySize")->value();

  // Get Wifi Range
  root_node = root_node->next_sibling("Wifi");
  metaData.wifiRange = root_node->first_attribute("range")->value();

  // Get Bluetooth Range
  root_node = root_node->next_sibling("Bluetooth");
  metaData.bluetoothRange = root_node->first_attribute("range")->value();

  // Get root taxis node
  root_node = root_node->next_sibling();

  // Iterate over the taxis
	for(xml_node<> *taxi_node = root_node->first_node("Taxi"); taxi_node; taxi_node = taxi_node->next_sibling("Taxi"))
	{
    // Temp variables
    Taxi temp;
    xml_node<> *taxiInfo_node;

    // Taxi location xCoord and yCoord
    taxiInfo_node = taxi_node->first_node("Location");
    temp.locationXCoord = taxiInfo_node->first_attribute("xCoord")->value();
    temp.locationYCoord = taxiInfo_node->first_attribute("yCoord")->value();

    // Taxi destination xCoord and yCoord
    taxiInfo_node = taxiInfo_node->next_sibling("Destination");
    temp.destinationXCoord = taxiInfo_node->first_attribute("xCoord")->value();
    temp.destinationYCoord = taxiInfo_node->first_attribute("xCoord")->value();

    // Taxi speed
    taxiInfo_node = taxiInfo_node->next_sibling("Speed");
    temp.speed = taxiInfo_node->first_attribute("value")->value();

    taxis.push_back(temp);
	}

  return true;
}
