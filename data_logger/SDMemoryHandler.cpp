#include "SDMemoryHandler.h"

void SDMemoryHandler::init(uint8_t sd_cspin){
    //Initialize the SD Memory
    while(!SD.begin(sd_cspin)){
        Serial.println("SD Card Initialization Failed");
        delay(1000);
    }
}

        //returns logMode
bool SDMemoryHandler::inLogMode(){
    return this->logMode;
}

void SDMemoryHandler::enableLogMode(String fileName){
    //open a file with the file object
    if(this->logMode){
      return;
    }

    file = SD.open(fileName, FILE_WRITE);
    if(!file){
      Serial.println("Cannot open the file: " + fileName);
      return;
    }
    logMode = true;
      
    
}

void SDMemoryHandler::writeMemory(String data){
    if(!(this->logMode)){
        return;
    }
    file.println(data);
    file.flush(); //Ensure all files are written to the SD Card
}

void SDMemoryHandler::disableLogMode(){
    if(!this->logMode){
      return;
    }

    file.close();
    logMode = false;
}