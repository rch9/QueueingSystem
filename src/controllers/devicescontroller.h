#ifndef DEVICECONTROLLER_H
#define DEVICECONTROLLER_H

#include "../timeableClasses/device.h"
#include <list>
#include <ostream>

class DevicesController
{
public:
//    DevicesController(int amountDevices);
    DevicesController();

    void init(const int &amount);
    void putBidToDevice(Bid bid);

    float getMinDeviceTime() const;

    friend std::ostream& operator<< (std::ostream& os, const DevicesController& arg) {
        os << "Devices:\n";
        for(auto it = arg._devices.begin(); it != arg._devices.end(); ++it) {
            os << (*it).getTime() << "\n";
        }
        os << "\n";

        return os;
    }

private:
    void moveDevicePointer();

private:
    std::list<Device> _devices;
    int _currentDevice;
    int _amountDevices;
};

#endif // DEVICECONTROLLER_H
