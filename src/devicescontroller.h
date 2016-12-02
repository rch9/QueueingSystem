#ifndef DEVICECONTROLLER_H
#define DEVICECONTROLLER_H

#include <list>
#include "device.h"


class DevicesController
{
public:
//    DevicesController(int amountDevices);
    DevicesController();

    void init(const int &amount);
    void putBidToDevice(Bid bid);

    float getMinDeviceTime() const;
    //опасность
//    int getAmountDevices();

private:
    void moveDevicePointer();

private:
    std::list<Device> _devices;
    int _currentDevice;
    int _amountDevices;
};

#endif // DEVICECONTROLLER_H
