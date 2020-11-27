#ifndef IO_H_
#define IO_H_

class ioHandler
{
public:
    ioHandler(int outputPin);
    ~ioHandler();

    void turnOn();
    void turnOff();

private:
    int pin;
};

#endif