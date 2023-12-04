#include "..\includes\sensor.h"
#include <chrono>
#include <cstdlib>
#include <thread>
#include <future>

sensor::sensor()
{
}

sensor::~sensor()
{
}

// return random integer between 0 and 5 every 60ms
void sensor::sens_data(std::promise<int> &&p, int i)
{   
    srand(time(NULL) * i);
    p.set_value(rand() % 6);
    std::this_thread::sleep_for(std::chrono::milliseconds(60));
}