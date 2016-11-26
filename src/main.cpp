#include <fstream>
#include "simulation.h"
#include "rapidxml-1.13/rapidxml.hpp"

using namespace std;
using namespace rapidxml;

/* Reads in all data from the given XML configFile. */
bool readIn(Simulation *taxiSimulation);

int main()
{
  // Create new taxi simulation
  Simulation *taxiSimulation = new Simulation();

  // Read in data from XML config file
  if(!readIn(taxiSimulation))
  {
    cout << "ERROR: Error in reading in XML file\n";
    return 0;
  }

  // Start taxi simulation
  taxiSimulation->startSimulation();

  // Delete taxi simulation
  delete taxiSimulation;

  return 0;
}

bool readIn(Simulation *taxiSimulation)
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
  taxiSimulation->setMapXSize(root_node->first_attribute("xSize")->value());
  taxiSimulation->setMapYSize(root_node->first_attribute("ySize")->value());

  // Get Wifi Range
  root_node = root_node->next_sibling("Wifi");
  taxiSimulation->setWifiRange(root_node->first_attribute("range")->value());

  // Get Bluetooth Range
  root_node = root_node->next_sibling("Bluetooth");
  taxiSimulation->setBluetoothRange(root_node->first_attribute("range")->value());

  // Get root taxis node
  root_node = root_node->next_sibling("Taxis");

  // Iterate over the taxis
	for(xml_node<> *taxi_node = root_node->first_node("Taxi"); taxi_node; taxi_node = taxi_node->next_sibling("Taxi"))
	{
    // Temp variables
    Taxi temp;
    xml_node<> *taxiInfo_node;

    // Taxi location xCoord and yCoord
    taxiInfo_node = taxi_node->first_node("Location");
    temp.setLocationXCoord(taxiInfo_node->first_attribute("xCoord")->value());
    temp.setLocationYCoord(taxiInfo_node->first_attribute("yCoord")->value());

    // Taxi destination xCoord and yCoord
    taxiInfo_node = taxiInfo_node->next_sibling("Destination");
    temp.setDestinationXCoord(taxiInfo_node->first_attribute("xCoord")->value());
    temp.setDestinationYCoord(taxiInfo_node->first_attribute("yCoord")->value());

    // Taxi speed
    taxiInfo_node = taxiInfo_node->next_sibling("Speed");
    temp.setSpeed(taxiInfo_node->first_attribute("value")->value());

    // Add taxi to vector of taxis
    taxiSimulation->addTaxi(temp);
	}

  // Deallocate buffer vector
  vector<char>().swap(buffer);

  return true;
}
