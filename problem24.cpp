// Project Euler (http://projecteuler.net/)
// Problem 24
//
// A permutation is an ordered arrangement of objects. For example, 3124 is one
// possible permutation of the digits 1, 2, 3 and 4. If all of the permutations
// are listed numerically or alphabetically, we call it lexicographic order. The
// lexicographic permutations of 0, 1 and 2 are:
//
// 012   021   102   120   201   210
//
// What is the millionth lexicographic permutation of the
// digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
//
// Answer: 2783915460
// Execution time: 0m8.599s

// After coding up this solution, I found out there's an STL algorithm called
// next_permutation that would have made this problem much simpler...

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#include <boost/foreach.hpp>
#define foreach BOOST_FOREACH

vector<string> getPermutations(string chars)
{
  // Base case: permutations of a single character is just the character itself
  if (chars.length() == 1)
    return vector<string>(1, chars);

  // Recursive call to get permutations for all the characters except the first
  vector<string> sub_permutations =
    getPermutations(chars.substr(1, chars.length() - 1));

  // For each of the sub-permutations returned, insert our first character in
  // every possible position to get all possible permutations
  const char& first_char = chars[0];
  vector<string> permutations;

  foreach (const string& sub_perm, sub_permutations)
  {
    for (unsigned i = 0; i <= sub_perm.length(); ++i)
    {
      string sub_perm_copy = sub_perm;
      permutations.push_back(sub_perm_copy.insert(i, 1, first_char));
    }
  }

  return permutations;
}

int main()
{
  vector<string> permutations = getPermutations("0123456789");

  sort(permutations.begin(), permutations.end());

  cout << permutations[999999] << endl;
}
