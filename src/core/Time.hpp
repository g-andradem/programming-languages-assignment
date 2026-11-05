#pragma once

class Time
{
    private:
        float elapsedTime;

        int minutes;
        int seconds;
    public:
        Time();

        void update(float deltaTime);

        int getMinutes() const;
        int getSeconds() const;
};