#include "Time.hpp"

Time::Time()
    : elapsedTime(0.f),
      minutes(3),
      seconds(0)
{
}

void Time::update(float deltaTime)
{
    elapsedTime += deltaTime;

    // 1 segundo real = 1 minuto no jogo
    if (elapsedTime >= 1.f){
        elapsedTime -= 1.f;

        seconds--;

        if (seconds <= -1){
            seconds = 59;
            minutes--;
        }
    }
}

int Time::getMinutes() const{
    return minutes;
}

int Time::getSeconds() const{
    return seconds;
}