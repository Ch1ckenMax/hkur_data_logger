#include "packetHandler.h"

void PacketHandler::readData(DFRobot_MCP2515& can){
    //Whether there is data received from the buffer or not can be checked by the value returned from read function (If CAN_OK, there is data. If CAN_NOMSG, there is no data.
    int status = can.readMsgBuf(8, data);

    if(CAN_NOMSG == status){
      dataReceived = false;
      return;
    }

    dataReceived = true;

}

String PacketHandler::toString(){
    if(dataReceived){
        String outputString = "";
        for(int i = 0; i < 8; i++){
          outputString = outputString + String(data[i]) + " ";
        }
        //You can just print raw data here (i.e. the decimal representation [0-255] of each bytes)
        return outputString;
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