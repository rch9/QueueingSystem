#include "bid.h"

Bid::Bid(int source):
    _source(source) {
}

Bid::Bid():
    _source(-1) {
}

const int &Bid::getSource() const {
    return _source;
}
