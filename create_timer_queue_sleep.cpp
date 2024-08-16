#include "create_timer_queue_sleep.hpp"
#include "benchmark_utils.hpp"

HANDLE queue_event;
HANDLE g_timer_queue;

void CALLBACK timer_callback(PVOID lpParameter, BOOLEAN TimerOrWaitFired)
{
    SetEvent((HANDLE)lpParameter);
}

void create_timer_queue_sleep(int delay)
{
    auto timer = start_timer();

    queue_event = CreateEvent(NULL, TRUE, FALSE, NULL);
    if (queue_event == NULL)
    {
        std::cerr << "Failed to create event." << std::endl;
        return;
    }

    g_timer_queue = CreateTimerQueue();
    if (g_timer_queue == NULL)
    {
        std::cerr << "Failed to create timer queue." << std::endl;
        CloseHandle(queue_event);
        return;
    }

    HANDLE timer_handle;
    if (!CreateTimerQueueTimer(&timer_handle, g_timer_queue, timer_callback, queue_event, delay, 0, WT_EXECUTEONLYONCE))
    {
        std::cerr << "Failed to create timer queue timer." << std::endl;
        DeleteTimerQueue(g_timer_queue);
        CloseHandle(queue_event);
        return;
    }

    WaitForSingleObject(queue_event, INFINITE);

    DeleteTimerQueueTimer(g_timer_queue, timer_handle, NULL);
    DeleteTimerQueue(g_timer_queue);
    CloseHandle(queue_event);

    stop_timer(timer, "CreateTimerQueueTimer()");
}