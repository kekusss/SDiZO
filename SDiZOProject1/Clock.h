#pragma once

#include <chrono>
#include <iostream>

using namespace std;

class Clock{
private:
    chrono::high_resolution_clock::time_point start;
    chrono::high_resolution_clock::time_point stop;

public:

    void beginTest();
    void endTest();
    long getTime();
    void displayTime();
};

