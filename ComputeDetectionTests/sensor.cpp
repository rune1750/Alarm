#include "sensor.h"
#include <cstdlib>
#include <ctime>


sensor::sensor()
{
}

sensor::~sensor()
{
}

// return random integer between 0 and 5 every 60ms
long sensor::sens_data()
{
    static long int x=123456789, y=362436069, z=521288629;
    long int t;
    x ^= x << 16;
    x ^= x >> 5;
    x ^= x << 1;

    t = x;
    x = y;
    y = z;
    z = t ^ x ^ y;

    if(z < 0){
        z*=-1;
    }

  return z % 6;
}
