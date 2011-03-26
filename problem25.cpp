// Project Euler (http://projecteuler.net/)
// Problem 25
//
//The Fibonacci sequence is defined by the recurrence relation:
//
// F(n) = F(n-1) + F(n-2), where F(1) = 1 and F(2) = 1.
//
// Hence the first 12 terms will be:
//
// F(1) = 1
// F(2) = 1
// F(3) = 2
// F(4) = 3
// F(5) = 5
// F(6) = 8
// F(7) = 13
// F(8) = 21
// F(9) = 34
// F(10) = 55
// F(11) = 89
// F(12) = 144
//
// The 12th term, F(12), is the first term to contain three digits.
//
// What is the first term in the Fibonacci sequence to contain 1000 digits?
//
// Answer: 4782
// Execution time: 0m0.033s

// This solution uses The GNU Multiple Precision Arithmetic Library
// http://gmplib.org/

#include <gmpxx.h>
#include <iostream>

using namespace std;

int main()
{
  // GMP integer
  mpz_class f1 = 1, f2 = 1;

  for (int term = 3; ; ++term)
  {
    mpz_class sum = f1 + f2;

    if (sum.get_str().length() >= 1000)
    {
      cout << term << endl;
      break;
    }

    f1 = f2;
    f2 = sum;
  }
}
