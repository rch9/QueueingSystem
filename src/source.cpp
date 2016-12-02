#include "source.h"
#include "randomhelper.h"

Source::Source(float first, float second):
    Controller(),
    _first(first),
    _second(second) {
    addServiceTime();
}

Bid Source::generateBid() {
    addServiceTime();
    return Bid(/*другое*/_time, _number);
}

float Source::distributionLaw() {
    return RandomHelper::rand_uniform(_first, _second);
}
