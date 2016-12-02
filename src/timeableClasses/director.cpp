#include "director.h"

Director &Director::getInstance() {
    static Director director;

    return director;
}

void Director::setTime(const float &time) {
    _time = time;
}

Director::Director():
    Timeable(0) {
}
