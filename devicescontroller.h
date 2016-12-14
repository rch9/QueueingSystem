#ifndef DEVICECONTROLLER_H
#define DEVICECONTROLLER_H

#include "device.h"
//#include <list>
#include <deque>
#include <ostream>
#include <initializer_list>

class DevicesController
{
public:
    DevicesController();


    void init(std::initializer_list<float> args);
    void putBidToDevice(const Bid &bid);

    float getMinDeviceTime() const;

    void freeReadyDevices();

    friend std::ostream& operator<< (std::ostream& os, const DevicesController& arg) {
        os << "Devices:\n";
        for(auto it = arg._devices.begin(); it != arg._devices.end(); ++it) {
            os << "Dev T: " << (*it).getTime() << " Bid T: " << (*it).getBid().getTime()
               << " Bid S: " << (*it).getBid().getSource() << "\n";
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
