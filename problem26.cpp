// Project Euler (http://projecteuler.net/)
// Problem 26
//
// A unit fraction contains 1 in the numerator. The decimal representation of
// the unit fractions with denominators 2 to 10 are given:
//
// 1/2	= 0.5
// 1/3	= 0.(3)
// 1/4	= 0.25
// 1/5	= 0.2
// 1/6	= 0.1(6)
// 1/7	= 0.(142857)
// 1/8	= 0.125
// 1/9	= 0.(1)
// 1/10	= 0.1
//
// Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be
// seen that 1/7 has a 6-digit recurring cycle.
//
// Find the value of d < 1000 for which 1/d contains the longest recurring cycle
// in its decimal fraction part.
//
// Answer: 983
// Execution time: 0m0.096s

#include <iostream>
#include <map>

using namespace std;

int main()
{
  int max_cycle_length = 0;
  int answer = 0;

  for (int divisor = 2; divisor < 1000; ++divisor)
  {
    // Keep track of each remainder. When we hit a remainder we've already come
    // across, we know we've reached the end of a cycle.
    map<int, int> remainders;

    // Our initial remainder is 10 since none of the numbers divide into 1
    for (int remainder = 10, i = 0; ; remainder *= 10, ++i)
    {
      // No cycle (or a 1-digit cycle of 0 if you prefer)
      if (!remainder)
        break;

      if (remainders.count(remainder) > 0)
      {
        // We've seen this remainder before, subtract its position from our
        // current position to find the cycle length
        int cycle_length = i - remainders[remainder];

        if (cycle_length > max_cycle_length)
        {
          max_cycle_length = cycle_length;
          answer = divisor;
        }
        
        break;
      }

      // Add this remainder and its position to our map
      remainders[remainder] = i;

      // Calculate our next remainder
      remainder %= divisor;
    }
  }

  cout << answer << endl;
}
