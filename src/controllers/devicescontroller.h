#ifndef DEVICECONTROLLER_H
#define DEVICECONTROLLER_H

#include "../timeableClasses/device.h"
//#include <list>
#include <deque>
#include <ostream>

class DevicesController
{
public:
//    DevicesController(int amountDevices);
    DevicesController();

//    void f(const int&... args);

    void init(int amount);
//    void init(int ... args1);
    void putBidToDevice(const Bid &bid);

    float getMinDeviceTime() const;

    friend std::ostream& operator<< (std::ostream& os, const DevicesController& arg) {
        os << "Devices:\n";
        for(auto it = arg._devices.begin(); it != arg._devices.end(); ++it) {
            os << (*it).getTime() << "\n";
        }

        return os;
    }

private:
    void moveDevicePointer();

private:
    std::deque<Device> _devices;
    int _currentDevice;
    int _amountDevices;
};

#endif // DEVICECONTROLLER_H
