#pragma once

#include <chrono>
class Stopwatch
{
public:
    std::chrono::high_resolution_clock::time_point startTime;
    std::chrono::high_resolution_clock::time_point endTime;
    bool isRunning;

    Stopwatch();

    void Start();
    void Stop();
    void Reset();
    double ElapsedMilliseconds();

};

