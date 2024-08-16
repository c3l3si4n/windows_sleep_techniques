#include "busy_sleep.hpp"
#include "benchmark_utils.hpp"

void busy_sleep(int delay_ms)
{
    auto timer = start_timer();

    LARGE_INTEGER frequency;
    LARGE_INTEGER start;
    LARGE_INTEGER current;

    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start);

    double elapsed_ms = 0;
    while (elapsed_ms < delay_ms)
    {
        QueryPerformanceCounter(&current);
        elapsed_ms = (current.QuadPart - start.QuadPart) * 1000.0 / frequency.QuadPart;
    }

    stop_timer(timer, "busy_sleep()");
}