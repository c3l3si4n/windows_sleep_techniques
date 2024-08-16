#pragma once
#include <Windows.h>
#include <iostream>
#include <chrono>

std::chrono::steady_clock::time_point start_timer();

void stop_timer(std::chrono::steady_clock::time_point start, std::string message);
