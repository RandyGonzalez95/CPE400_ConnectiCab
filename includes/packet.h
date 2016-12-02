#ifndef PACKET_H
#define PACKET_H

#include <string>

class Packet {

  public:
    Packet();
    Packet(int source, int destination, int destinationXCoord, int destinationYCoord, int speed);

    // Data member gets
    int getDestinationTaxi(); // Get Destination taxi

  private:
    int sourceTaxi;
    int destinationTaxi;
    std::string message;
};

#endif // PACKET_H
