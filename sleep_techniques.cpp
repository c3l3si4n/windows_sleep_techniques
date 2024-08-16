// sleep_techniques.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <time.h>

#include <Windows.h>

#include <mmsystem.h>

#include "multimedia_timers.hpp"
#include "standard_sleep.hpp"
#include "create_timer_queue_sleep.hpp"
#include "ping_sleep.hpp"
#include "busy_sleep.hpp"
#include <Windows.h>
#include <chrono>
#include <iostream>
#include "idle_event_timeout_sleep.hpp"

int main()
{
    StandardSleep(1000);
    MultimediaTimerSleep(1000);
    create_timer_queue_sleep(1000);
    busy_sleep(1000);
    ping_sleep(1);
    idle_event_timeout_sleep(1000);
}

