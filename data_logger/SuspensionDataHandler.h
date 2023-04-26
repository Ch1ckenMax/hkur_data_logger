#ifndef SUS_HANDLER
#define SUS_HANDLER
#include <Arduino.h>

class SusHandler{
  private:
    double data[4];

  public:
    void readData(uint8_t pinA, uint8_t pinB, uint8_t pinC, uint8_t pinD);
    const double* getDataArray();
    String toString(int decimalPlaces);

};

#endif