// Project Euler (http://projecteuler.net/)
// Problem 7
//
// By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see
// that the 6th prime is 13.
//
// What is the 10001st prime number?
//
// Answer: 104743
// Execution time: 0m0.007s

#include <iostream>

#include "prime.h"

using namespace std;

int main()
{
  int prime_count = 0;

  for (int i = 2; ; ++i)
  {
    if (Prime::isPrime(i))
    {
      if (++prime_count == 10001)
      {
        cout << i << endl;
        break;
      }
    }
  }
}
