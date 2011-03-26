// Project Euler (http://projecteuler.net/)
// Problem 23
//
// A perfect number is a number for which the sum of its proper divisors is
// exactly equal to the number. For example, the sum of the proper divisors of 
// 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.
//
// A number n is called deficient if the sum of its proper divisors is less
// than n and it is called abundant if this sum exceeds n.
//
// As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest
// number that can be written as the sum of two abundant numbers is 24. By
// mathematical analysis, it can be shown that all integers greater than
// 28123 can be written as the sum of two abundant numbers. However, this upper
// limit cannot be reduced any further by analysis even though it is known that
// the greatest number that cannot be expressed as the sum of two abundant
// numbers is less than this limit.
//
// Find the sum of all the positive integers which cannot be written as the sum
// of two abundant numbers.
//
// Answer: 4179871
// Execution time: 0m0.100s

#include <iostream>

#include "euler.h"

using namespace std;

int main()
{
  bool abundant_nums[28123];

  // Find abundant numbers where any pair's sum would be <= 28123
  for (unsigned i = 0; i < 28123; ++i)
    abundant_nums[i] = Euler::getDivisorSum(i) - i > i;

  unsigned non_abundant_sum_sum = 0;

  for (unsigned candidate = 1; candidate <= 28123; ++candidate)
  {
    bool is_abundant_sum = false;

    for (unsigned first_term = 1; first_term <= candidate / 2; ++first_term)
    {
      if (abundant_nums[first_term] && abundant_nums[candidate - first_term])
      {
        is_abundant_sum = true;
        break;
      }
    }

    if (!is_abundant_sum)
      non_abundant_sum_sum += candidate;
  }

  cout << non_abundant_sum_sum << endl;
}
