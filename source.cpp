#include "source.h"
#include "randomhelper.h"

Source::Source(float first, float second, int number):
    Controller(),
    _first(first),
    _second(second),
    _number(number),
    _bidNumber(0) {
    addServiceTime();
}

Bid Source::generateBid() {    
    Bid bid(_time, _number, _bidNumber);
    ++_bidNumber;
    addServiceTime();

    return bid;
}

const int &Source::getBidNumber() const {
    return _bidNumber;
}

float Source::distributionLaw() {
    return RandomHelper::rand_uniform(_first, _second);
}
