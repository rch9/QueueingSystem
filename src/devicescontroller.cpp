#include "devicescontroller.h"

//need fix param
//DevicesController::DevicesController(int amountDevices):
//    _currentDevice(0),
//    _amountDevices(amountDevices) {
//}

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

void DevicesController::moveDevicePointer() {
    if (++_currentDevice == _amountDevices) {
        _currentDevice = 0;
    }
}

//int DevicesController::getAmountDevices() {
//    return _amountDevices;
//}
