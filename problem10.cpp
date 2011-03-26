// Project Euler (http://projecteuler.net/)
// Problem 10
//
// The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
//
// Find the sum of all the primes below two million.
//
// Answer: 142913828922
// Execution time: 0m0.232s

#include <iostream>

#include "euler.h"

using namespace std;

int main()
{
  vector<bool> sieve = Euler::getPrimeSieve(2000000);

  long long sum = 0;

  for (int i = 0; i < 2000000; ++i)
  {
    if (sieve[i])
    {
      sum += i;
    }
  }

  cout << sum << endl;
}
