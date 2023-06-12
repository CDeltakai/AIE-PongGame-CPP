#include "Stopwatch.h"
#include <iostream>

Stopwatch::Stopwatch()
{
    isRunning = false;
}

void Stopwatch::Start() 
{
    std::cout << "Attempted to start stopwatch\n";

    if (!isRunning) 
    {
        startTime = std::chrono::high_resolution_clock::now();
        isRunning = true;
    }
}

void Stopwatch::Stop() {
    if (isRunning) {
        endTime = std::chrono::high_resolution_clock::now();
        isRunning = false;
    }
}

void Stopwatch::Reset() {
    isRunning = false;
}

double Stopwatch::ElapsedMilliseconds() {
    //std::cout << "Measuring elapsed milliseconds\n";
    std::chrono::high_resolution_clock::time_point endTimeCopy;

    if (isRunning) 
    {
        endTimeCopy = std::chrono::high_resolution_clock::now();
    }
    else {
        endTimeCopy = endTime;
    }

    std::chrono::duration<double, std::milli> duration = endTimeCopy - startTime;

    //std::cout << "elapsed milliseconds: " << duration.count() << "\n";
    return duration.count();
}