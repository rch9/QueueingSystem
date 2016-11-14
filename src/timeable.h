#ifndef TIMEABLE_H
#define TIMEABLE_H


/**
 * @brief The Timeable class
 * от этого класса наследуется всё связанное с временем
 */


class Timeable
{
public:
    Timeable(float time = 0);


    const float &getTime() const;

protected:
    float _time;
};

#endif // TIMEABLE_H
