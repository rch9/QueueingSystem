#ifndef RANDOMHELPER_H
#define RANDOMHELPER_H


#include <random>


class RandomHelper
{
public:
    RandomHelper();

    static float rand_exponential(const float &lambda);
    static float rand_uniform(const int &first, const int &second);

private:


};

#endif // RANDOMHELPER_H
