#include "bitcounter.h"

BitCounter::BitCounter():
    _failure(0.f),
    _treadted(0.f) {
}


//FIXME! need return pointer
BitCounter BitCounter::getInstance() {
    static BitCounter bitCounter;

    return bitCounter;
}

void BitCounter::increseFailure() {
    ++_failure;
}

void BitCounter::increseTreaded() {
    ++_treadted;
}

void BitCounter::decreseFailure() {
    --_treadted;
}

void BitCounter::decreseTreaded() {
    --_treadted;
}

float BitCounter::getFailureProbably() const {
    return _failure / (_failure + _treadted);
}
