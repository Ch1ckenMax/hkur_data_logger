#include <DFRobot_MCP2515.h>
#include "constants.h"
#include "packetHandler.h"
#include "SDMemoryHandler.h"

DFRobot_MCP2515 can(csPIN);
//Create SD Object

PacketHandler packetHandler;
SDMemoryHandler memoryHandler;

void setup() {
  //Set up serial (for screen output)
    Serial.begin(SERIAL_BAUDRATE);

    //Setup pins (not necessary for now)
    
    //Set up CAN
    while(can.begin(CAN_BAUDRATE) == CAN_FAILINIT){ 
        Serial.println("DFROBOT's CAN BUS Shield init fail");
        Serial.println("Please Init CAN BUS Shield again");
        delay(1000); //Retry connection every one second
    }
    Serial.println("DFROBOT's CAN BUS Shield init ok!\n");

    //Set up SD
    memoryHandler.init();

}

void loop() {
    //Log mode on/off

    //Handle and read data
    
    if(memoryHandler.inLogMode()){
        packetHandler.readData(can);
        if(packetHandler.hasDataReceived()){
            Serial.println(packetHandler.toReadableString());
            memoryHandler.writeMemory(packetHandler.toString());
        }
    }
    
}
