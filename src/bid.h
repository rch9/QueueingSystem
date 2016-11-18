#ifndef BID_H
#define BID_H

#include "timeable.h"

/**
 * @brief The Bid class
 */

class Bid : public Timeable {
public:
    Bid(float time, int source);
    Bid();
    ~Bid();
    const int &getSource() const;

private:
    int _source;
};

#endif // BID_H
