#ifndef CONSTANTS
#define CONSTANTS

//CAN
const int SERIAL_BAUDRATE = 9600;
const int CAN_BAUDRATE = CAN_250KBPS;
const uint8_t csPIN = 10;

//SD Card
const uint8_t csPIN_SD = 4;

//toggle pin for turning on/off the log mode
const uint8_t OFF_PIN = 13;

//Suspension
const uint8_t SUS_PINA = A0;
const uint8_t SUS_PINB = A1;
const uint8_t SUS_PINC = A2;
const uint8_t SUS_PIND = A3;

#endif