#include "ping_sleep.hpp"
#include "benchmark_utils.hpp"

void ping_sleep(int seconds)
{
    auto timer = start_timer();

    std::string command = "ping -n " + std::to_string(seconds + 1) + " 127.0.0.1 > nul";

    int result = system(command.c_str());

    if (result != 0)
    {
        std::cerr << "Failed to execute ping command." << std::endl;
    }

    stop_timer(timer, "ping_sleep()");
}