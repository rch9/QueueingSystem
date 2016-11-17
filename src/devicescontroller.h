#ifndef DEVICECONTROLLER_H
#define DEVICECONTROLLER_H

#include <vector>
#include "device.h"


class DevicesController
{
public:
    DevicesController(int amountDevices);

    //опасность
    int getAmountDevices();

private:
    void moveDevicePointer();

private:
    std::vector<Device> _devices;
    int _currentDevice;
    int _amountDevices;
};

#endif // DEVICECONTROLLER_H