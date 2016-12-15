#ifndef BID_H
#define BID_H

#include "timeable.h"

/**
 * @brief The Bid class
 */

class Bid : public Timeable {
public:
    Bid(float time, int source, int number);
    Bid();
    ~Bid();
    const int &getSource() const;

    const int &getNumber() const;

private:
    int _source;
    int _number;
};

#endif // BID_H
