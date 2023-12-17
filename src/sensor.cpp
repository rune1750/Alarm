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
int sensor::sens_data()
{
    srand(time(NULL));
    return (rand() % 6);
}