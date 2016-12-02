#ifndef DIRECTOR_H
#define DIRECTOR_H


class Director
{
public:
    static Director &getInstance();

    const float &getGlobalTime() const;
    void addGlobalTime(const float &dt);

private:
    Director();
private:
    float _globalTime;
};

#endif // DIRECTOR_H
