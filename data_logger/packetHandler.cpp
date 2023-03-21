#include "packetHandler.h"

void PacketHandler::readData(DFRobot_MCP2515& can){
    //Whether there is data received from the buffer or not can be checked by the value returned from read function (If CAN_OK, there is data. If CAN_NOMSG, there is no data.
}

String PacketHandler::toString(){
    if(dataReceived){
        //You can just print raw data here (i.e. the decimal representation [0-255] of each bytes)
        return "TO BE IMPLEMENTED";
    }
    else{
        return "";
    }
}

String PacketHandler::toReadableString(){
    if(dataReceived){
        return "TO BE IMPLEMENTED";
    }
    else{
        return "";
    }
}

bool PacketHandler::hasDataReceived(){
    return this->dataReceived;
}