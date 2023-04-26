    #include "SuspensionDataHandler.h"
    #include <Arduino.h>
    
    void SusHandler::readData(uint8_t pinA, uint8_t pinB, uint8_t pinC, uint8_t pinD){
      data[0] = analogRead(pinA);
      data[1] = analogRead(pinB);
      data[2] = analogRead(pinC);
      data[3] = analogRead(pinD);
    }
    const double* SusHandler::getDataArray(){
      return data;
    }
    String SusHandler::toString(int decimalPlaces){
      return String(data[0], decimalPlaces) + " " + String(data[1], decimalPlaces) + " " + String(data[2], decimalPlaces) + " " + String(data[3], decimalPlaces);
    }