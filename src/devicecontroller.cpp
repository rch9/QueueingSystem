#include "devicecontroller.h"

//need fix param
DevicesController::DevicesController():
    _currentDevice(0),
    _amountDevices(0) {
}

void DevicesController::moveDevicePointer() {
    if (++_currentDevice == _amountDevices) {
        _currentDevice = 0;
    }
}
