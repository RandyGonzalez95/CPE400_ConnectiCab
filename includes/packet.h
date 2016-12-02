#ifndef PACKET_H
#define PACKET_H

#include <string>

class Packet {

  public:
    Packet();
    Packet(int source, int destination, int destinationXCoord, int destinationYCoord, int speed);
int destinationTaxi;
  private:
    int sourceTaxi;

    std::string message;
};

#endif // PACKET_H
