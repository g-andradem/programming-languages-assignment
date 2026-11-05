#pragma once

class Score
{
    private:
        int points;
    public:
        Score();

        void update(float deltaTime);

        void addPoints(int amount);
        void removePoints(int amount);

        int getPoints() const;
        void reset();
};