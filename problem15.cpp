// Project Euler (http://projecteuler.net/)
// Problem 15
//
// Starting in the top left corner of a 2x2 grid, there are 6 routes (without
// backtracking) to the bottom right corner.
//
// How many routes are there through a 20x20 grid?
//
// Answer: 137846528820
// Execution time: 0m0.002s

// This solution creates a 2D array to mark the total routes from each location
// to the destination. We know that the entire bottom and right sides of the
// grid all have only one path to the destination, and we also know that the
// number of routes from a position is equal to the sum of the routes from its
// right and bottom neighbors. Knowing this, we can start in the bottom right
// corner and make our way to the top left, the top left position being the
// answer.

#include <iostream>

using namespace std;

int main()
{
  unsigned long long grid[21][21];

  for (int i = 0; i < 21; ++i)
    grid[i][20] = grid[20][i] = 1;

  for (int row = 19; row >= 0; --row)
    for (int col = row; col >= 0; --col)
      grid[row][col] = grid[row + 1][col] + grid[row][col + 1];

  cout << grid[0][0] << endl;
}
