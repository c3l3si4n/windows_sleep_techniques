#include "idle_event_timeout_sleep.hpp"
#include "benchmark_utils.hpp"
#include <string>
HANDLE infiniteEvent;


void idle_event_timeout_sleep(int delay)
{
    auto timer = start_timer();

    infiniteEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
    std::cout << "Created event" << infiniteEvent << std::endl;
    WaitForSingleObject(infiniteEvent, delay);

  
    CloseHandle(infiniteEvent);

    stop_timer(timer, "WaitForSingleObject()");
}