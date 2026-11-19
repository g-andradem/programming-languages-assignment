#pragma once

class Score
{
    private:
        int points;

    public:
        Score();

        void addPoints(int amount);
        int getPoints() const;
        void reset();
};