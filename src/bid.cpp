#include "bid.h"

Bid::Bid(float time, int source):
    Timeable(time),
    _source(source) {
}

Bid::Bid():
    Timeable(-1.f),
    _source(-1) {
}

const int &Bid::getSource() const {
    return _source;
}
