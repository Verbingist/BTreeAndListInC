#ifndef TIMER
#define TIMER

class Timer
{
public:
    void startTimer();
    void endTimer();
    long long getTime();

private:
    long long start;
    long long end;
};

#endif