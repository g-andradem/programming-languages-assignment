#include "Timer.hpp"

Timer::Timer(float duration)
    : elapsedTime(0.f),
      duration(duration)
{}

void Timer::update(float deltaTime)
{
    elapsedTime += deltaTime;
}

bool Timer::isFinished() const
{
    return elapsedTime >= duration;
}

void Timer::reset()
{
    elapsedTime = 0.f;
}

float Timer::getElapsedTime() const
{
    return elapsedTime;
}