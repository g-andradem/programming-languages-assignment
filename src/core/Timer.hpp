// Time usa Timer
// Player usa Timer
// Score apenas controla points

#pragma once

class Timer
{
private:
    float elapsedTime;
    float duration;

public:
    Timer(float duration);

    void update(float deltaTime);

    bool isFinished() const;

    void reset();

    float getElapsedTime() const;
};