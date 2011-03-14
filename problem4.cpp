// Project Euler (http://projecteuler.net/)
// Problem 4
//
// A palindromic number reads the same both ways. The largest palindrome made
// from the product of two 2-digit numbers is 9009 = 91 x 99.
//
// Find the largest palindrome made from the product of two 3-digit numbers.
//
// Answer: 906609
// Execution time: 0m0.016s

// The palindrome will be of the form abccba, which can be expanded to:
//   100000a + 10000b + 1000c + 100c + 10b + a
// = 100001a + 10010b + 1100c
// = 11(9091a + 910b + 100c)
//
// Therefore the palindrome will be divisible by 11. Since 11 is prime, one of
// the two factors has to be divisible by 11.

#include <cstdio>
#include <cstring>

int main()
{
  int max = 0;

  for (int i = 100; i < 1000; ++i)
  {
    // Make the second factor a multiple of 11
    for (int j = 110; j < 1000; j += 11)
    {
      int product = i * j;
      char str[7];
      snprintf(str, 7, "%d", product);

      bool is_palindrome = true;
      for (int front = 0, back = strlen(str) - 1; front < back; ++front, --back)
      {
        if (str[front] != str[back])
        {
          is_palindrome = false;
          break;
        }
      }

      if (is_palindrome && product > max)
        max = product;
    }
  }

  printf("%d", max);
}
