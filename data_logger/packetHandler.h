#ifndef PACKET_HANDLER
#define PACKET_HANDLER
#include <Arduino.h>
#include <DFRobot_MCP2515.h>

class PacketHandler{
    private:
        uint8_t data[8];
        bool dataReceived = false;
    public:
        //Check if there is any data in the CAN receive buffer. If yes, set dataReceived to true and store the data to data array. Otherwise, set dataReceived to false.
        void readData(DFRobot_MCP2515& can);

        //translate the data in the data array to a string.
        //function result is valid if and only if dataReceived = true. If dataReceived = false, returns a null string.
        String toString();

        //translate the data in the data array to a human-readable string.
        //function result is valid if and only if dataReceived = true. If dataReceived = false, returns a null string.
        String toReadableString();

        //Check if there is any data in the buffer
        bool hasDataReceived();
};

#endif