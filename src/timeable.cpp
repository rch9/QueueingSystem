#include "timeable.h"

Timeable::Timeable(float time):
    _time(time ){
}

const float &Timeable::getTime() const {
    return _time;
}
