#ifndef DEVICECONTROLLER_H
#define DEVICECONTROLLER_H

#include <vector>
#include "device.h"


class DevicesController
{
public:
    DevicesController();

private:
    void moveDevicePointer();

private:
    std::vector<Device> _devices;
    int _currentDevice;
    static int AMOUNT_DEVICES;
};

#endif // DEVICECONTROLLER_H
