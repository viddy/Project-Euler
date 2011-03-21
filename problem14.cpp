// Project Euler (http://projecteuler.net/)
// Problem 14
//
// The following iterative sequence is defined for the set of positive integers:
//
// n -> n/2 (n is even)
// n -> 3n + 1 (n is odd)
//
// Using the rule above and starting with 13, we generate the following
// sequence:
//
// 13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
//
// It can be seen that this sequence (starting at 13 and finishing at 1)
// contains 10 terms. Although it has not been proved yet (Collatz Problem), it
// is thought that all starting numbers finish at 1.
//
// Which starting number, under one million, produces the longest chain?
//
// NOTE: Once the chain starts the terms are allowed to go above one million.
//
// Answer: 837799
// Execution time: 0m0.052s

#include <iostream>

using namespace std;

int main()
{
  int max_chain_length = 0;
  int answer = 0;

  // Cache chain lengths for speed
  int chain_lengths[1000000] = {0};

  for (int n = 1; n < 1000000; ++n)
  {
    int chain_length = 1;
    long n_copy = n;
    while (n_copy != 1)
    {
      if (n_copy % 2 == 0)
        n_copy /= 2;
      else
        n_copy = 3 * n_copy + 1;

      if (n_copy < 1000000 && chain_lengths[n_copy])
      {
        chain_length += chain_lengths[n_copy];
        break;
      }

      ++chain_length;
    }

    chain_lengths[n] = chain_length;

    if (chain_length > max_chain_length)
    {
      max_chain_length = chain_length;
      answer = n;
    }
  }

  cout << answer << endl;
}
