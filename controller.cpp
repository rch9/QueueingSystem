#include "controller.h"
#include "director.h"
#include <iostream>

Controller::Controller(int number):
    Timeable(0.f),
    _number(number) {
}

const int &Controller::getNumber() const {
    return _number;
}

void Controller::addServiceTime() {
    _time = Director::getInstance()->getTime() + distributionLaw();
}
