#include "Score.hpp"

// Construtor dos Pontos
Score::Score(): 
    points(0)
{}

// Adicionar Pontos
void Score::addPoints(int amount)
{
    points += amount;
}

// Getter dos Pontos
int Score::getPoints() const
{
    return points;
}

// Reset dos Pontos
void Score::reset()
{
    points = 0;
}