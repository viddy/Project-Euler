// Project Euler (http://projecteuler.net/)
//
// This file contains general purpose prime number functions.

#include <math.h>
#include <vector>

using namespace std;

class Prime
{
  public:

  static bool isPrime(int num)
  {
    if (num == 2 || num == 3)
      return true;

    if (num % 2 == 0 || num % 3 == 0)
      return false;

    int num_sqrt = sqrt(num) + 1;
    for (int k = 6; k <= num_sqrt; k += 6)
    {
      if (num % (k - 1) == 0 || num % (k + 1) == 0)
        return false;
    }

    return true;
  }

  static vector<bool> getPrimeSieve(int upper_limit)
  {
    vector<bool> sieve(upper_limit, 1);

    sieve[0] = 0;
    sieve[1] = 0;

    for (int i = 2; i <= sqrt(upper_limit); ++i)
    {
      if (sieve[i])
      {
        for (int j = i; j <= upper_limit / i ; ++j)
        {
          sieve[i * j] = 0;
        }
      }
    }

    return sieve;
  }
};
