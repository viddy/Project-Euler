// Project Euler (http://projecteuler.net/)
// Problem 28
//
// Starting with the number 1 and moving to the right in a clockwise direction
// a 5 by 5 spiral is formed as follows:
//
// 21 22 23 24 25
// 20  7  8  9 10
// 19  6  1  2 11
// 18  5  4  3 12
// 17 16 15 14 13
//
// It can be verified that the sum of the numbers on the diagonals is 101.
//
// What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral
// formed in the same way?
//
// Answer: 669171007
// Execution time: 0m0.002s

#include <iostream>

using namespace std;

int main()
{
  int diagonal_sum = 1;

  // For each "box" around the center, the average of its numbers is the number
  // in the middle of the left side (e.g., first box average is 6, second is
  // 19). Therefore, the sum of each box's corners is this average number * 4.
  // For each successive box, the average number increases by a multiple of 8,
  // plus five. Since each box adds 2 row/cols to the spiral, we have to do
  // 1000/2 = 500 iterations.
  for (int i = 0; i < 500; ++i)
  {
    static int avg_num = 1;

    avg_num += i*8 + 5;

    diagonal_sum += avg_num * 4;
  }

  cout << diagonal_sum << endl;
}
