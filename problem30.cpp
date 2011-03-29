// Project Euler (http://projecteuler.net/)
// Problem 30
//
// Surprisingly there are only three numbers that can be written as the sum of
// fourth powers of their digits:
//
// 1634 = 1^4 + 6^4 + 3^4 + 4^4
// 8208 = 8^4 + 2^4 + 0^4 + 8^4
// 9474 = 9^4 + 4^4 + 7^4 + 4^4
//
// As 1 = 1^4 is not a sum it is not included.
//
// The sum of these numbers is 1634 + 8208 + 9474 = 19316.
//
// Find the sum of all the numbers that can be written as the sum of fifth
// powers of their digits.
//
// Answer: 443839
// Execution time: 0m0.182s

#include <iostream>
#include <math.h>
#include <numeric>
#include <vector>

using namespace std;

int main()
{
  vector<int> numbers;

  // Since 99999 = 5 * 9^5 = 295245 and 999999 = 6 * 9^5 = 354294, we can see
  // it's possible for a six digit number to succeed, but not a seven.
  for (int i = 2; i < 1000000; ++i)
  {
    int number = i;
    double sum_of_fifth_powers = 0.0;

    do
      sum_of_fifth_powers += pow(number % 10, 5.0);
    while((number /= 10) > 0);

    if (sum_of_fifth_powers == i)
      numbers.push_back(i);
  }

  cout << accumulate(numbers.begin(), numbers.end(), 0) << endl;
}

