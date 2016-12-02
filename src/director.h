#ifndef DIRECTOR_H
#define DIRECTOR_H


class Director
{
    static Director &getInstance();

private:
    Director();
private:
    float _globalTime;
};

#endif // DIRECTOR_H
