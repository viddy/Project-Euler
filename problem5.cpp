// Project Euler (http://projecteuler.net/)
// Problem 5
//
// 2520 is the smallest number that can be divided by each of the numbers from
// 1 to 10 without any remainder.
//
// What is the smallest positive number that is evenly divisible by all of the
// numbers from 1 to 20?
//
// Answer: 232792560
// Execution time: 0m1.453s

#include <iostream>

using namespace std;

int main()
{
  int i = 2520;
  while (++i)
  {
    // Don't have to include 1-10 since they all divide evenly into 11-20
    if (i % 11 == 0 && i % 12 == 0 && i % 13 == 0 && i % 14 == 0 && i % 15 == 0 &&
        i % 16 == 0 && i % 17 == 0 && i % 18 == 0 && i % 19 == 0 && i % 20 == 0 )
      break;
  }

  cout << i << endl;

}
