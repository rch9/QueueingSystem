#ifndef BUFFER_H
#define BUFFER_H

#include "bid.h"
#include <list>

class Buffer {
public:
//    Buffer(int maxSize);
    Buffer();

    void init(int maxSize);

    void putBid(const Bid &bid);
    Bid popBid();

    unsigned size();

private:
    std::list<Bid> _bids;
    int _maxSize;
};

#endif // BUFFER_H
