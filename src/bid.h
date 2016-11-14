#ifndef BID_H
#define BID_H

#include "timeable.h"

/**
 * @brief The Bid class
 */

class Bid : public Timeable {
public:
    Bid(int source);
    int getSource() const;

private:
    int _source;
};

#endif // BID_H
