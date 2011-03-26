// Project Euler (http://projecteuler.net/)
// Problem 22
//
// Using names.txt, a 46K text file containing over five-thousand first names,
// begin by sorting it into alphabetical order. Then working out the
// alphabetical value for each name, multiply this value by its alphabetical
// position in the list to obtain a name score.
//
// For example, when the list is sorted into alphabetical order, COLIN, which is
// worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN
// would obtain a score of 938 x 53 = 49714.
//
// What is the total of all the name scores in the file?
//
// Answer: 871198282
// Execution time: 0m0.009s

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
  ifstream names_file("names.txt");

  if (!names_file.is_open())
  {
    cout << "Error opening \"names.txt\"" << endl;
    return EXIT_FAILURE;
  }

  vector<string> names;
  
  // Names are surrounding by quotes and are separated by commas
  while (!names_file.eof())
  {
    names.push_back("");

    // Discard opening quote
    names_file.get();

    // Read name up to closing quote
    getline(names_file, names.back(), '"');

    // Discard comma
    names_file.get();
  }

  names_file.close();

  // Alphabetize names
  sort(names.begin(), names.end());

  unsigned total_name_score = 0;

  for (unsigned name_pos = 0; name_pos < names.size(); ++name_pos)
  {
    const string& name = names[name_pos];
    unsigned name_score = 0;

    for (unsigned char_pos = 0; char_pos < name.length(); ++char_pos)
    {
      // Add up letter values
      name_score += name[char_pos] - 'A' + 1;
    }

    // Multiply alphabetical value of name by its position in the list
    name_score *= name_pos + 1;

    total_name_score += name_score;
  }

  cout << total_name_score << endl;
}
