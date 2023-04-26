#include <DFRobot_MCP2515.h>
#include "constants.h"
#include "packetHandler.h"
#include "SDMemoryHandler.h"
#include "SuspensionDataHandler.h"

DFRobot_MCP2515 can(csPIN);
//Create SD Object

PacketHandler packetHandler;
SDMemoryHandler memoryHandler;
SusHandler susHandler;

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
    memoryHandler.init(csPIN_SD);

    //Enable log mode
    memoryHandler.enableLogMode(String(millis()));

    //Pin to turn off logMode
    pinMode(OFF_PIN, OUTPUT);

}

void loop() {
    //Log mode off
    if(digitalRead(OFF_PIN == HIGH)){
        Serial.println("Log mode is off");
        memoryHandler.disableLogMode();
    }

    //Handle and read data
    
    if(memoryHandler.inLogMode()){
        //Write CAN data
        packetHandler.readData(can);
        if(packetHandler.hasDataReceived()){
            Serial.println(packetHandler.toString());
            memoryHandler.writeMemory(packetHandler.toString());
        }

        //Write SD Card Data
        susHandler.readData(SUS_PINA, SUS_PINB, SUS_PINC, SUS_PIND);
        memoryHandler.writeMemory(susHandler.toString(4));
        Serial.println(susHandler.toString(4));
    }
    
}
