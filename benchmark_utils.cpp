#include <Windows.h>
#include <iostream>
#include <chrono>

std::chrono::steady_clock::time_point start_timer() {
		return std::chrono::high_resolution_clock::now();
}

void stop_timer(std::chrono::steady_clock::time_point start, std::string message) {
	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
	std::cout << "Slept for " << elapsed << " milliseconds using " << message << std::endl;
}

