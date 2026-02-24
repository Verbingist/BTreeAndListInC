#include <chrono>

class Timer
{
public:
    void startTimer();
    void endTimer();
    auto getTime();

private:
    std::chrono::steady_clock::time_point start;
    std::chrono::steady_clock::time_point end;
};