#include "multimedia_timers.hpp"
#include "benchmark_utils.hpp"

HANDLE g_event;

void CALLBACK TimerCallback(UINT uTimerID, UINT uMsg, DWORD_PTR dwUser, DWORD_PTR dw1, DWORD_PTR dw2)
{
    SetEvent((HANDLE)dwUser);
}

void MultimediaTimerSleep(int delay)
{
    auto timer = start_timer();

    g_event = CreateEvent(NULL, TRUE, FALSE, NULL);
    if (g_event == NULL)
    {
        std::cerr << "Failed to create event." << std::endl;
        return;
    }

    UINT timerID = timeSetEvent(delay, 1, TimerCallback, (DWORD_PTR)g_event, TIME_ONESHOT);
    if (timerID == 0)
    {
        std::cerr << "Failed to set timer." << std::endl;
        CloseHandle(g_event);
        return;
    }


    WaitForSingleObject(g_event, INFINITE);
    timeKillEvent(timerID);
    CloseHandle(g_event);


    stop_timer(timer, "timeSetEvent()");
}