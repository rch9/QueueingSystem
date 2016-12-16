#include "controller.h"
#include "director.h"
#include <iostream>

Controller::Controller():
    Timeable(0.f) {
}

//const Bid *Controller::getBid() const {
//    return _bid;
//}

//void Controller::freeController() {
//    _bid = Bid();
//}

//const bool &Controller::isFree() const {
//    return _isFree;
//}

void Controller::addServiceTime() {
    _time = Director::getInstance().getTime() + distributionLaw();
}
