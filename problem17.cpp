// Project Euler (http://projecteuler.net/)
// Problem 17
//
// If the numbers 1 to 5 are written out in words: one, two, three, four, five,
// then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
//
// If all the numbers from 1 to 1000 (one thousand) inclusive were written out
// in words, how many letters would be used?
//
// NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and
// forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20
// letters. The use of "and" when writing out numbers is in compliance with
// British usage.
//
// Answer: 21124
// Execution time: 0m0.003s

#include <iostream>
#include <map>

using namespace std;

map<int, int> letter_lookup;

void buildLetterLookup();

int main()
{

  buildLetterLookup();

  int total_letters = 0;

  for (int i = 1; i < 1000; ++i)
  {
    int number = i;

    if (number > 99)
    {
      total_letters += letter_lookup[number / 100]; // hundreds digit
      total_letters += 7; // "hundred"

      number %= 100;

      if (number)
        total_letters += 3; // "and"
    }

    if (number > 19)
    {
      total_letters += letter_lookup[(number / 10) * 10]; // tens

      number %= 10;
    }

    if (number)
      total_letters += letter_lookup[number]; // "one" through "nineteen"
  }

  total_letters += 11; // "one thousand"

  cout << total_letters << endl;
}

void buildLetterLookup()
{
  letter_lookup[1] = 3; // one
  letter_lookup[2] = 3; // two
  letter_lookup[3] = 5; // three
  letter_lookup[4] = 4; // four
  letter_lookup[5] = 4; // five
  letter_lookup[6] = 3; // six
  letter_lookup[7] = 5; // seven
  letter_lookup[8] = 5; // eight
  letter_lookup[9] = 4; // nine

  letter_lookup[10] = 3; // ten
  letter_lookup[11] = 6; // eleven
  letter_lookup[12] = 6; // twelve
  letter_lookup[13] = 8; // thirteen
  letter_lookup[14] = 8; // fourteen
  letter_lookup[15] = 7; // fifteen
  letter_lookup[16] = 7; // sixteen
  letter_lookup[17] = 9; // seventeen
  letter_lookup[18] = 8; // eighteen
  letter_lookup[19] = 8; // nineteen

  letter_lookup[20] = 6; // twenty
  letter_lookup[30] = 6; // thirty
  letter_lookup[40] = 5; // forty
  letter_lookup[50] = 5; // fifty
  letter_lookup[60] = 5; // sixty
  letter_lookup[70] = 7; // seventy
  letter_lookup[80] = 6; // eighty
  letter_lookup[90] = 6; // ninety
}
