#include "source.h"
#include "randomhelper.h"

Source::Source(float first, float second):
    _first(first),
    _second(second) {
}

float Source::distributionLaw() {
    return RandomHelper::rand_uniform(_first, _second);
}
