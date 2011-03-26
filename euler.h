// Project Euler (http://projecteuler.net/)
//
// This file contains general purpose functions.

#include <math.h>
#include <vector>

using namespace std;

class Euler
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

  static unsigned getDivisorSum(unsigned num)
  {
    // Returns the sum of num's divisors. For example, an input of
    // 12 would return 1 + 2 + 3 + 4 + 6 + 12 = 28

    if (num < 2)
      return num;

    unsigned div_sum = 1 + num;
    unsigned num_sqrt = sqrt(num);

    // When we find a divisor, we know num/div is also a divisor
    for (unsigned div = 2; div <= num_sqrt; ++div)
      if (num % div == 0)
        div_sum += div + num/div;

    // If num was a perfect square, we would've added its square root twice
    if (num_sqrt * num_sqrt == num)
      div_sum -= num_sqrt;

    return div_sum;
  }
};
