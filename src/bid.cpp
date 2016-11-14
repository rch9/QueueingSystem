#include "bid.h"

Bid::Bid(int source):
    _source(source) {
}

const int &Bid::getSource() const {
    return _source;
}
