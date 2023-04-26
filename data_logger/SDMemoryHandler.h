#ifndef MEMORY_HANDLER
#define MEMORY_HANDLER
#include <Arduino.h>
#include <SD.h>

class SDMemoryHandler{
    private:
        bool logMode;
        File file;
        //file object
        
    public:
        //Initialize the SD Memory. Should be called in the setup() function
        void init(uint8_t sd_cspin);

        //returns logMode
        bool inLogMode();

        //Start logging data by creating a file with the fileName 
        //Set logMode = true
        void enableLogMode(String fileName);

        //Write to the SD Card
        //function is valid if and only if logMode = true
        void writeMemory(String data);

        //Stop logging data by closing the opened file
        //Set logMode = false
        void disableLogMode();
};

#endif