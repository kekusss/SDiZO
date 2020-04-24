#include "Clock.h"

/*
Zegar s³u¿¹cy do pomiarow
*/

void Clock::beginTest() {
    start = chrono::high_resolution_clock::now();
}

void Clock::endTest() {
    stop = chrono::high_resolution_clock::now();
}

long Clock::getTime() {
    return chrono::duration_cast<chrono::nanoseconds>(stop - start).count();
}

void Clock::displayTime() {
    cout << getTime() << "[ns] \n";
}