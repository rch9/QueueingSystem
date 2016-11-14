#include "devicecontroller.h"

//need fix param
DevicesController::DevicesController(int amountDevices):
    _currentDevice(0),
    AMOUNT_DEVICES(amountDevices) {
}

void DevicesController::moveDevicePointer() {
    if (++_currentDevice == AMOUNT_DEVICES) {
        _currentDevice = 0;
    }
}
