// Project Euler (http://projecteuler.net/)
// Problem 6
//
// The sum of the squares of the first ten natural numbers is,
//
// 1^2 + 2^2 + ... + 10^2 = 385
//
// The square of the sum of the first ten natural numbers is,
//
// (1 + 2 + ... + 10)^2 = 55^2 = 3025
//
// Hence the difference between the sum of the squares of the first ten natural
// numbers and the square of the sum is 3025  385 = 2640.
//
// Find the difference between the sum of the squares of the first one hundred
// natural numbers and the square of the sum.
//
// Answer: 25164150
// Execution time: 0m0.002s

// This solution uses the simple formulas for summing each sequence.
// They can be found online.

#include <iostream>

using namespace std;

int main()
{
  int n = 100;

  int sum_of_squares = (n * (n + 1) * (2 * n + 1)) / 6;

  int square_of_sums = (n * (n + 1)) / 2;
  square_of_sums *= square_of_sums;

  cout << square_of_sums - sum_of_squares << endl;
}
