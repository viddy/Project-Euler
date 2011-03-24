// Project Euler (http://projecteuler.net/)
// Problem 20
//
// n! means n x (n - 1) x ... x 3 x 2 x 1
//
// For example, 10! = 10 x 9 x ... x 3 x 2 x 1 = 3628800, and the sum of the
// digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
//
// Find the sum of the digits in the number 100!
//
// Answer: 648
// Execution time: 0m0.002s

// This solution uses The GNU Multiple Precision Arithmetic Library
// http://gmplib.org/

#include <gmpxx.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
  // GMP integer
  mpz_class product = 1;

  for (int i = 2; i <= 100; ++i)
    product *= i;

  string product_str = product.get_str();

  int digit_sum = 0;

  for (unsigned int i = 0; i < product_str.length(); ++i)
    digit_sum += product_str[i] - '0';

  cout << digit_sum << endl;
}
