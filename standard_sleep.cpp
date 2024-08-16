#include "standard_sleep.hpp"   
// Standard Sleep() from WinAPI
void StandardSleep(int delay) {
    // get current timestamp using time.h down to miliseconds
    auto start = std::chrono::high_resolution_clock::now();
    // sleep for 1 second
    Sleep(delay);
    // get current timestamp using time.h
    auto end = std::chrono::high_resolution_clock::now();

    // calculate the difference between the two timestamps
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "Slept for " << elapsed << " milliseconds using Sleep()" << std::endl;

}