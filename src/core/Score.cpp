#include "Score.hpp"

Score::Score(): 
    points(0)
{}

void Score::addPoints(int amount)
{
    points += amount;
}

void Score::removePoints(int amount)
{
    points -= amount;

    if (points < 0) {
        points = 0;
    }
}

int Score::getPoints() const
{
    return points;
}

void Score::reset()
{
    points = 0;
}