#include "SDMemoryHandler.h"

void SDMemoryHandler::init(){
    //Initialize the SD Memory
}

        //returns logMode
bool SDMemoryHandler::inLogMode(){
    return this->logMode;
}

void SDMemoryHandler::enableLogMode(String fileName){
    //if file is already opened (i.e. logMode already true), take appropriate action... ?
    
    //open a file with the file object
}

void SDMemoryHandler::writeMemory(String data){
    if(!(this->logMode)){
        return;
    }

    //Do Somehing here
}

void SDMemoryHandler::disableLogMode(){
    //Do something here
}