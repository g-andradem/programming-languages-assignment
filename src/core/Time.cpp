#include "Time.hpp"

// Construtor do Tempo
Time::Time(): 
    elapsedTime(0.f),
    minutes(2),
    seconds(0)
{
}

// Update do Tempo
void Time::update(float deltaTime)
{
    elapsedTime += deltaTime;

    if (elapsedTime >= 1.f){
        elapsedTime -= 1.f;

        seconds--;

        if (seconds <= -1){
            seconds = 59;
            minutes--;
        }
    }
}

// Getter dos Minutos
int Time::getMinutes() const
{
    return minutes;
}

// Getter dos Seconds
int Time::getSeconds() const
{
    return seconds;
}

// Resetar o Tempo
void Time::reset()
{
    minutes = 2;
    seconds = 0;
}