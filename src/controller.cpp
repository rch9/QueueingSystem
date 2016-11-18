#include "controller.h"

Controller::Controller():
    Timeable(0.f),
    _isFree(false),
    _maxTime(0.f) {
}

void Controller::putBid(const Bid &bid) {
    _isFree = false;
    _bid = bid;
}

void Controller::popBid() {
    _isFree = true;
    // вероятно не надо
}

const bool &Controller::isFree() {
    return _isFree;
}

void Controller::addServiceTime() {
    _time += distributionLaw();
}
