#include "buffer.h"
#include "devicescontroller.h"
#include "layer.h"
#include "director.h"

using namespace std;

Buffer::Buffer() {
}

void Buffer::init(int maxSize) {
    _maxSize = maxSize;
}

void Buffer::putBid(const Bid &bid) {
    if (_bids.size() == _maxSize) {
        //отказ
        _bids.back().setInBufferStartTime(Director::getInstance()->getTime());
        StatisticsInfoManager::getInstance()->addedFailureBid(_bids.back());
        _bids.pop_back();
    }

    const_cast<Bid&>(bid).setInBufferStartTime(Director::getInstance()->getTime());
    StatisticsInfoManager::getInstance()->addedBidToBuffer(bid);
    _bids.push_back(bid);
}

Bid Buffer::popBid() {
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

unsigned Buffer::size() {
    return _bids.size();
}

const std::list<Bid> &Buffer::getBids() const {
    return _bids;
}
