#pragma once

class Score
{
public:
    Score();

    void update(float deltaTime);

    void addPoints(int amount);
    void removePoints(int amount);

    int getPoints() const;
    void reset();

private:
    int points;
};