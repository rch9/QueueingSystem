#include "bid.h"
//#include "iostream"

Bid::Bid(float time, int source):
    Timeable(time),
    _source(source) {
//    std::cout << "bid(a, b)";
}

Bid::Bid():
    Timeable(-1.f),
    _source(-1) {
//    std::cout << "bid()";
}

Bid::~Bid() {
//    std::cout << "destroy";
}

const int &Bid::getSource() const {
    return _source;
}
