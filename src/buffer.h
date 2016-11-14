#ifndef BUFFER_H
#define BUFFER_H

#include "bid.h"
#include <list>

class Buffer {
public:
    Buffer();

    void putBid(const Bid &bid);
    const Bid &&popBid();

private:
    std::list<Bid> _bids;
};

#endif // BUFFER_H
