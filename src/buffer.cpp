#include "buffer.h"
#include "devicecontroller.h"

Buffer::Buffer(int maxSize) {
    _bids.resize(maxSize);
}

void Buffer::putBid(const Bid &bid) {
    if (_bids.size() == _bids.max_size()) {
        _bids.pop_back();
    }

    _bids.push_back(bid);
}

const Bid &&Buffer::popBid() {
    return Bid();
}
