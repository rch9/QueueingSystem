#ifndef BITCOUNTER_H
#define BITCOUNTER_H


class BitCounter {
public:
    BitCounter();

    BitCounter getInstance();

    void increseFailure();
    void increseTreaded();

    void decreseFailure();
    void decreseTreaded();

    float getFailureProbably() const;
private:
    float _failure;
    float _treadted;
};

#endif // BITCOUNTER_H
