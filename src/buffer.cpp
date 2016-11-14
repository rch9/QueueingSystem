#include "buffer.h"
#include "devicecontroller.h"

using namespace std;

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
    auto buf = _bids.begin();
    for(auto it = _bids.begin(); it != _bids.end(); ++it) {
        if (it->getSource() < buf->getSource()) {
            buf = it;
        }
    }
    auto bid = *buf;
    _bids.erase(buf);

    return bid;
}
