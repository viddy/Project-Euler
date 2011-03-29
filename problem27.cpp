// Project Euler (http://projecteuler.net/)
// Problem 27
//
// Euler published the remarkable quadratic formula:
//
// n² + n + 41
//
// It turns out that the formula will produce 40 primes for the consecutive
// values n = 0 to 39. However, when n = 40, 40² + 40 + 41 = 40(40 + 1) + 41 is
// divisible by 41, and certainly when n = 41, 41² + 41 + 41 is clearly
// divisible by 41.
//
// Using computers, the incredible formula n² - 79n + 1601 was discovered, which
// produces 80 primes for the consecutive values n = 0 to 79. The product of the
// coefficients, -79 and 1601, is -126479.
//
// Considering quadratics of the form:
//
// n² + an + b, where |a| < 1000 and |b| < 1000
//
// where |n| is the modulus/absolute value of n, e.g. |11| = 11 and |-4| = 4
//
// Find the product of the coefficients, a and b, for the quadratic expression
// that produces the maximum number of primes for consecutive values of n,
// starting with n = 0.
//
// Answer: -59231
// Execution time: 0m0.112s

#include <iostream>

#include "euler.h"

using namespace std;

int main()
{
  int max_prime_count = 0;
  int answer = 0;

  // We know n won't become greater than 79, so the maximum prime we'll have to
  // test for is 79^2 + 999*79 + 999 = 86161
  vector<bool> prime_sieve = Euler::getPrimeSieve(86161);

  for (int a = -999; a < 1000; ++a)
  {
    for (int b = -999; b < 1000; ++b)
    {
      int prime_count = 0;

      for (int n = 0; ; ++n)
      {
        int possible_prime = n*n + a*n + b;
        
        if (possible_prime > 1 && prime_sieve[possible_prime])
          ++prime_count;
        else
          break;
      }

      if (prime_count > max_prime_count)
      {
        max_prime_count = prime_count;
        answer = a*b;
      }
    }
  }

  cout << answer << endl;
}
