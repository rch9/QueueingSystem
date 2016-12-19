#include "devicescontroller.h"
#include "director.h"
#include <iostream>

DevicesController::DevicesController():
    _currentDevice(0) {
}

void DevicesController::init(std::vector<float> args) {
    _amountDevices = args.size();
    for (auto arg: args) {
        _devices.push_back(Device(arg, _devices.size()));
    }
}

void DevicesController::putBidToDevice(const Bid &bid) {
    for (int i = 0; i < _amountDevices; ++i) {
        if (_devices.at(_currentDevice).getIsFree()) {
            _devices.at(_currentDevice).putBid(bid);
//            std::cout << "\nDevice p: " << _currentDevice << std::endl;
            break;
        }        

        moveDevicePointer();
    }
    moveDevicePointer();
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

float DevicesController::getMinBusyDeviceTime() const {

    float t = -1.f;

    for(size_t i = 0; i < _devices.size(); ++i) {
        if (!_devices.at(i).getIsFree()) {
            if ((t < 0.f) || (t > _devices.at(i).getTime())) {
                t = _devices.at(i).getTime();
            }
        }
    }

    return t;
}

void DevicesController::freeReadyDevices() {

    for(size_t i = 0; i < _devices.size(); ++i) {
        if (_devices.at(i).getIsFree()) {
//            device.setTime(Director::getInstance()->getTime());
        } else {
            if (_devices.at(i).getTime() <= Director::getInstance()->getTime()) {
                _devices.at(i).freeBid();
//                std::cout << "\n\nfffffffffff\n\n";
            }
        }
    }

}

void DevicesController::updateFreeDevices() {


    for(size_t i = 0; i < _devices.size(); ++i) {
        if(_devices.at(i).getIsFree()) {
            _devices.at(i).setTime(Director::getInstance()->getTime());
        }
    }

}

void DevicesController::moveDevicePointer() {

    if (++_currentDevice == _amountDevices) {
        _currentDevice = 0;
    }
}

const std::deque<Device> &DevicesController::getDevices() const {
    return _devices;
}

bool DevicesController::hasFreeDevice() const {
    for (size_t i = 0; i < _devices.size(); ++i) {
        if (_devices.at(i).getIsFree()) {
            return true;
        }
    }

    return false;
}
