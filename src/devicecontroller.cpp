#include "devicecontroller.h"

//need fix param
DevicesController::DevicesController(int amountDevices):
    _currentDevice(0),
    _amountDevices(amountDevices) {
}

void DevicesController::moveDevicePointer() {
    if (++_currentDevice == _amountDevices) {
        _currentDevice = 0;
    }
}

int DevicesController::getAmountDevices() {
    return _amountDevices;
}
