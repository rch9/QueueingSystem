#include "director.h"
#include <iostream>

Director *Director::getInstance() {
    static Director director;

    return &director;
}

void Director::setTime(const float &time) {
    _time = time;
}

void Director::cleanAll() {
    _time = 0.f;
}

Director::Director():
    Timeable(0) {    
}
