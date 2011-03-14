// Project Euler (http://projecteuler.net/)
//
// This file contains general purpose prime number functions.

#include <math.h>

bool isPrime(int num)
{
  if (num % 2 == 0 || num % 3 == 0)
    return false;

  int num_sqrt = sqrt(num);
  for (int k = 30; k <= num_sqrt; k += 30)
  {
    if (num % (k + 1) == 0  || num % (k + 7) == 0  || num % (k + 11) == 0 ||
        num % (k + 13) == 0 || num % (k + 17) == 0 || num % (k + 19) == 0 ||
        num % (k + 23) == 0 || num % (k + 29) == 0)
      return false;
  }

  return true;
}

