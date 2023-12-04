#include "includes\sensor.h"
#include "includes\camera.h"
#include "includes\alarm_system.h"
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>

int main()
{
    // Create sensor and camera objects
    sensor s1;
    sensor s2;
    camera C;

    // Create alarm system object
    alarm_system A(&s1, &s2, &C);

    // start system
    std::thread one(&alarm_system::start_system, &A);

    while (A.p % 2 != 0)
    {
        A.pin();
    };

    // Start a chrono timer
    auto start = std::chrono::high_resolution_clock::now();
    while (true)
    {
        // if the system has been running for 10 seconds, kill it
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        if (elapsed.count() > 60)
        {
            A.kill();
            break;
        }
        };

    return 0;
}