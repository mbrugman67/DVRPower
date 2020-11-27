#include "io.h"
    
#include <wiringPi.h>
#include <iostream>
    
ioHandler::ioHandler(int outputPin) : pin(outputPin)
{
    wiringPiSetup();
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
}

ioHandler::~ioHandler()
{
    digitalWrite(pin, LOW);
}


void ioHandler::turnOn()
{
    digitalWrite(pin, HIGH);
}

void ioHandler::turnOff()
{
    digitalWrite(pin, LOW);
}
