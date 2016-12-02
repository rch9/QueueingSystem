#include "director.h"

Director &Director::getInstance() {
    static Director director;

    return director;
}

void Director::addGlobalTime(const float &dt) {
    _globalTime += dt;
}

Director::Director():
    Timeable(0) {
}
