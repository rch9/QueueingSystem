#include "source.h"
#include "randomhelper.h"

Source::Source(float first, float second):
    Controller(),
    _first(first),
    _second(second) {
}

Bid Source::generateBid() const {
    return Bid(/*другое*/_time, _number);
}

float Source::distributionLaw() {
    return RandomHelper::rand_uniform(_first, _second);
}
