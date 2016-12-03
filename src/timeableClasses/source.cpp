#include "source.h"
#include "../utils/randomhelper.h"

Source::Source(float first, float second, int number):
    Controller(),
    _first(first),
    _second(second),
    _number(number) {
    addServiceTime();
}

Bid Source::generateBid() {
    Bid bid(_time, _number);
    addServiceTime();

    return bid;
}

float Source::distributionLaw() {
    return RandomHelper::rand_uniform(_first, _second);
}
