#pragma once

class Time
{
public:
    Time();

    void update(float deltaTime);

    int getMinutes() const;
    int getSeconds() const;

private:
    float elapsedTime;

    int minutes;
    int seconds;
};