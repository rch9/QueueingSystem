#include "devicescontroller.h"

DevicesController::DevicesController():
    _currentDevice(0) {
}

void DevicesController::init(const int &amount) {
    _amountDevices = amount;
    for(int i = 0; i < amount; ++i) {
        _devices.push_back(Device(1));
    }
}

void DevicesController::putBidToDevice(Bid bid) {

}

float DevicesController::getMinDeviceTime() const {
    auto minIt = _devices.begin();
    for(auto it = _devices.begin(); it != _devices.end(); ++it) {
        if ((*it).getTime() < (*minIt).getTime()) {
            minIt = it;
        }
    }

    return (*minIt).getTime();
}

void DevicesController::moveDevicePointer() {
    if (++_currentDevice == _amountDevices) {
        _currentDevice = 0;
    }
}
