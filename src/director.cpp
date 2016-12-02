#include "director.h"

Director &Director::getInstance() {
    static Director director;

    return director;
}

const float &Director::getGlobalTime() const {
    return _globalTime;
}

void Director::addGlobalTime(const float &dt) {
    _globalTime += dt;
}

Director::Director():
    _globalTime(0.f) {
}
