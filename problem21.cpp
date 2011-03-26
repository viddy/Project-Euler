// Project Euler (http://projecteuler.net/)
// Problem 21
//
// Let d(n) be defined as the sum of proper divisors of n (numbers less than n
// which divide evenly into n).
// If d(a) = b and d(b) = a, where a != b, then a and b are an amicable pair and
// each of a and b are called amicable numbers.
//
// For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44,
// 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4,
// 71 and 142; so d(284) = 220.
//
// Evaluate the sum of all the amicable numbers under 10000.
//
// Answer: 31626
// Execution time: 0m0.006s

#include <iostream>
#include <math.h>

#include "euler.h"

using namespace std;

int main()
{
  unsigned sum_of_divisors[10000];

  for (unsigned i = 1; i < 10000; ++i)
    sum_of_divisors[i] = Euler::getDivisorSum(i) - i;

  unsigned amicable_sum = 0;
  for (unsigned i = 1; i < 10000; ++i)
  {
    unsigned sum = sum_of_divisors[i];
    if (sum < 10000 && sum > 0 && sum != i && sum_of_divisors[sum] == i)
    {
      amicable_sum += i + sum;

      // Zero out these amicable numbers' sums so we don't add them twice
      sum_of_divisors[i] = 0;
      sum_of_divisors[sum] = 0;
    }
  }

  cout << amicable_sum << endl;
}
