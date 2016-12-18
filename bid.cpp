#include "bid.h"
//#include "iostream"

Bid::Bid(float time, int source, int number):
    Timeable(time),
    _source(source),
    _number(number),
    _device(-1),
    _inBufferStartTime(0.f),
    _inDeviceStartTime(0.f),
    _inSystemTime(0.f) {
}

Bid::Bid():
    Timeable(-1.f),
    _source(-1),
    _number(-1),
    _device(-1),
    _inBufferStartTime(0.f),
    _inDeviceStartTime(0.f),
    _inSystemTime(0.f) {
}

Bid::~Bid() {
}

const int &Bid::getSource() const {
    return _source;
}

const int &Bid::getNumber() const {
    return _number;
}

float Bid::getInBufferStartTime() const {
    return _inBufferStartTime;
}

void Bid::setInBufferStartTime(const float &inBufferStartTime) {
    _inBufferStartTime = inBufferStartTime;
}

float Bid::getInDeviceStartTime() const {
    return _inDeviceStartTime;
}

void Bid::setInDeviceStartTime(const float &inDeviceStartTime) {
    _inDeviceStartTime = inDeviceStartTime;
}

const float &Bid::getInSystemTime() const {
    return _inSystemTime;
}

void Bid::setInSystemTime(const float &inSystemTime) {
    _inSystemTime = inSystemTime;
}

const int &Bid::getDevice() const {
    return _device;
}

void Bid::setDevice(const int &device) {
    _device = device;
}
