#include "idle_event_timeout_sleep.hpp"
#include "benchmark_utils.hpp"

HANDLE infiniteEvent;


void idle_event_timeout_sleep(int delay)
{
    auto timer = start_timer();

    infiniteEvent = CreateEvent(NULL, TRUE, FALSE, NULL);

    WaitForSingleObject(infiniteEvent, delay);

  
    CloseHandle(infiniteEvent);

    stop_timer(timer, "WaitForSingleObject()");
}