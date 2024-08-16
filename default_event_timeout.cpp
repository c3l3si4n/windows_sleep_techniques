#include "default_event_timeout_sleep.hpp"
#include "benchmark_utils.hpp"
#include <string>
#include <Windows.h>

HANDLE discoveredHandle = NULL;


// Brute force method to discover a suitable handle, which wont answer fast so the timeout is triggered.
HANDLE discoverHandle() {
    for (DWORD i = 1; i <= 255; i++) {
        HANDLE handle = reinterpret_cast<HANDLE>(static_cast<ULONG_PTR>(i));
        DWORD result = WaitForSingleObject(handle, 1000);  // 150ms timeout
        if (result == WAIT_TIMEOUT) {
            return handle;
        }
    }
    return NULL;
}

void default_event_timeout_sleep(int delay) {
    auto timer = start_timer();

    if (discoveredHandle == NULL) {
        discoveredHandle = discoverHandle();
        if (discoveredHandle == NULL) {
            std::cout << "Failed to discover a suitable handle" << std::endl;
            return;
        }
        std::cout << "Discovered handle: " << discoveredHandle << std::endl;
    }

    WaitForSingleObject(discoveredHandle, delay);

    stop_timer(timer, "WaitForSingleObject()");
}