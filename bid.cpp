#include "bid.h"
//#include "iostream"

Bid::Bid(float time, int source, int number):
    Timeable(time),
    _source(source),
    _number(number) {
//    std::cout << "bid(a, b)";
}

Bid::Bid():
    Timeable(-1.f),
    _source(-1),
    _number(-1) {
//    std::cout << "bid()";
}

Bid::~Bid() {
//    std::cout << "destroy";
}

const int &Bid::getSource() const {
    return _source;
}

const int &Bid::getNumber() const
{
    return _number;
}
