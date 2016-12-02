#include "director.h"

Director &Director::getInstance() {
    static Director director;

    return director;
}

void Director::setTime(const float &time) {
    _time = time;
}

//void Director::addGlobalTime(const float &dt) {
//    _time += dt;
//}

Director::Director():
    Timeable(0) {
}
