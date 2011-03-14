// Project Euler (http://projecteuler.net/)
// Problem 3
//
// The prime factors of 13195 are 5, 7, 13 and 29.
//
// What is the largest prime factor of the number 600851475143 ?
//
// Answer: 6857
// Execution time: 0m0.015s

#include <iostream>
#include <math.h>

#include "prime.h"

using namespace std;

int main()
{
  for (int candidate = sqrt(600851475143); candidate > 1; --candidate)
  {
    if (600851475143 % candidate == 0 && isPrime(candidate))
    {
      cout << candidate << endl;
      break;
    }
  }
}
