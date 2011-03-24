// Project Euler (http://projecteuler.net/)
// Problem 16
//
// 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
//
// What is the sum of the digits of the number 2^1000?
//
// Answer: 1366
// Execution time: 0m0.006s

// Since 2^1000 won't fit in any of the available integer types, this solution
// stores the running product in a string and uses long multiplication.

#include <iostream>
#include <string>

using namespace std;

int main()
{
  string total = "1";

  for (int exp = 1; exp <= 1000; ++exp)
  {
    int carry = 0;

    for (int digit = total.length() - 1; digit >= 0; --digit)
    {
      int product = (total[digit] - '0') * 2 + carry;

      if (product > 9)
      {
        carry = 1;
        product %= 10;
      }
      else
      {
        carry = 0;
      }

      total[digit] = '0' + product;

      if (digit == 0 && carry == 1)
        total.insert(0, "1");
    }
  }

  int sum = 0;

  for (unsigned int digit = 0; digit < total.length(); ++digit)
    sum += total[digit] - '0';

  cout << sum << endl;
}
