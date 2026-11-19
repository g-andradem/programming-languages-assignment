#include "Timer.hpp"

// Construtor do Temporizador
Timer::Timer(float duration): 
    elapsedTime(0.f),
    duration(duration)
{}

// Update do Temporizador
void Timer::update(float deltaTime)
{
    elapsedTime += deltaTime;
}

// Verificador de Temporizador Finalizado
bool Timer::isFinished() const
{
    return elapsedTime >= duration;
}

// Reset do Temporizador
void Timer::reset()
{
    elapsedTime = 0.f;
}

// Getter do Tempo Decorrido
float Timer::getElapsedTime() const
{
    return elapsedTime;
}