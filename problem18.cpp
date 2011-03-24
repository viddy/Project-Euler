// Project Euler (http://projecteuler.net/)
// Problem 18
//
// By starting at the top of the triangle below and moving to adjacent numbers
// on the row below, the maximum total from top to bottom is 23.
//
//    3
//   7 4
//  2 4 6
// 8 5 9 3
//
// That is, 3 + 7 + 4 + 9 = 23.
//
// Find the maximum total from top to bottom of the triangle below:
//
//                             75
//                           95  64
//                         17  47  82
//                       18  35  87  10
//                     20  04  82  47  65
//                   19  01  23  75  03  34
//                 88  02  77  73  07  63  67
//               99  65  04  28  06  16  70  92
//             41  41  26  56  83  40  80  70  33
//           41  48  72  33  47  32  37  16  94  29
//         53  71  44  65  25  43  91  52  97  51  14
//       70  11  33  28  77  73  17  78  39  68  17  57
//     91  71  52  38  17  14  91  43  58  50  27  29  48
//   63  66  04  68  89  53  67  30  73  16  69  87  40  31
// 04  62  98  27  23  09  70  98  73  93  38  53  60  04  23
//
// NOTE: As there are only 16384 routes, it is possible to solve this problem by
// trying every route. However, Problem 67, is the same challenge with a
// triangle containing one-hundred rows; it cannot be solved by brute force, and
// requires a clever method! ;o)
//
// Answer: 1074
// Execution time: 0m0.002s

// This solution works from the bottom up to find the max sum. Starting in the
// second to last row, each number is added to the max adjacent number below it.
//
// For example, in the smaller triangle from the problem description, we would
// start in the row beginning with 2. The max adjacent number below 2 is 8, so
// we replace the 2 with 10. The 4 becomes 13 and the 6 becomes 15.
//
// Continuing this process for each row on the way to the top gives you the
// answer in the top position.

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string triangle =
"75 "
"95 64 "
"17 47 82 "
"18 35 87 10 "
"20 04 82 47 65 "
"19 01 23 75 03 34 "
"88 02 77 73 07 63 67 "
"99 65 04 28 06 16 70 92 "
"41 41 26 56 83 40 80 70 33 "
"41 48 72 33 47 32 37 16 94 29 "
"53 71 44 65 25 43 91 52 97 51 14 "
"70 11 33 28 77 73 17 78 39 68 17 57 "
"91 71 52 38 17 14 91 43 58 50 27 29 48 "
"63 66 04 68 89 53 67 30 73 16 69 87 40 31 "
"04 62 98 27 23 09 70 98 73 93 38 53 60 04 23";

const int ROWS = 15;

int main()
{
  stringstream ss(triangle, stringstream::in);

  vector< vector<int> > numbers;

  for (int i = 0; i < ROWS; ++i)
  {
    numbers.push_back(vector<int>());
    for (int j = 0; j < i + 1; ++j)
    {
      numbers[i].push_back(0);
      ss >> numbers[i][j];
    }
  }

  for (int i = ROWS - 2; i >= 0; --i)
    for (int j = i; j >= 0; --j)
      numbers[i][j] = numbers[i][j] + max(numbers[i+1][j], numbers[i+1][j+1]);

  cout << numbers[0][0] << endl;
}
