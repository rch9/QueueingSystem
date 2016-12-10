#include "controller.h"
#include "director.h"
#include <iostream>

Controller::Controller():
    Timeable(0.f) {
}

void Controller::addServiceTime() {
    _time = Director::getInstance()->getTime() + distributionLaw();
}
