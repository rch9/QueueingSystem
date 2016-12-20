#include "randomhelper.h"

RandomHelper::RandomHelper() {
}

float RandomHelper::rand_exponential(const float &lambda) {
//    static std::random_device rd;
//    static std::mt19937 gen(rd());
//    std::exponential_distribution<float> dist(lambda);
//    return dist(gen);

    float r = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
//    return lambda * exp(-lambda * r);

    return  fabs(log(r * lambda) / lambda);
}

float RandomHelper::rand_uniform(const int &first, const int &second) {
//    static std::random_device rd;
//    static std::mt19937 gen(rd());
//    std::uniform_real_distribution<float> dist(first, second);
//    return dist(gen);
    float r = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
    return first + second * r;

//    double var = 5*((double) rand() / (double)RAND_MAX);

}
