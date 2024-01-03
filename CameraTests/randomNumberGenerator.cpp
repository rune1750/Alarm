#include "iostream"

// Random number generator not using rand or time functions
// https://stackoverflow.com/questions/1640258/need-a-fast-random-generator-for-c


static long int x=123456789, y=362436069, z=521288629;   

inline long int xorshf96() {          //period 2^96-1
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

  return z;
}

// Random number algorithm




