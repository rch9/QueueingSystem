#ifndef BUFFER_H
#define BUFFER_H

#include "timeableClasses/bid.h"
#include <list>
#include <ostream>

class Buffer {
public:
//    Buffer(int maxSize);
    Buffer();

    void init(int maxSize);

    void putBid(const Bid &bid);
    Bid popBid();

    unsigned size();

    friend std::ostream& operator<< (std::ostream& os, const Buffer& arg) {
        os << "Buffer:\n";
        for(auto it = arg._bids.begin(); it != arg._bids.end(); ++it) {
            os << (*it).getTime() << "\n";
        }

        return os;
    }

private:
    std::list<Bid> _bids;
    int _maxSize;
};

#endif // BUFFER_H
