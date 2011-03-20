// Project Euler (http://projecteuler.net/)
// Problem 9
//
// A Pythagorean triplet is a set of three natural numbers, a < b < c,
// for which,
//
// a^2 + b^2 = c^2
//
// For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
//
// There exists exactly one Pythagorean triplet for which a + b + c = 1000.
// Find the product a * b * c.
//
// Answer: 31875000
// Execution time: 0m0.003s

#include <iostream>

using namespace std;

int main()
{
  for (int a = 1; a < 333; ++a)
  {
    for (int b = a + 1; b < (1000 - a) / 2; ++b)
    {
      int c = 1000 - b - a;
      if (a * a + b * b == c * c)
      {
        cout << a * b * c << endl;
        return 0;
      }
    }
  }
}
