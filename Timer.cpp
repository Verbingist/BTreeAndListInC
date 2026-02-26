#include "Timer.hpp"

void Timer::startTimer()
{
    start = std::chrono::steady_clock::now();
}
void Timer::endTimer()
{
    end = std::chrono::steady_clock::now();
}

long long Timer::getTime()
{
    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}