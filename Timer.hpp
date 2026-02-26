#ifndef TIMER
#define TIMER

#include <chrono>

class Timer
{
public:
    void startTimer();
    void endTimer();
    long long getTime();

private:
    std::chrono::steady_clock::time_point start;
    std::chrono::steady_clock::time_point end;
};

#endif