#include "Timer.hpp"

extern "C" long long getSystemTime();

void Timer::startTimer()
{
    start = getSystemTime();
}
void Timer::endTimer()
{
    end = getSystemTime();
}

long long Timer::getTime()
{
    return end - start;
}