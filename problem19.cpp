// Project Euler (http://projecteuler.net/)
// Problem 19
//
// You are given the following information, but you may prefer to do some
// research for yourself.
//
// - 1 Jan 1900 was a Monday.
// - Thirty days has September,
//   April, June and November.
//   All the rest have thirty-one,
//   Saving February alone,
//   Which has twenty-eight, rain or shine.
//   And on leap years, twenty-nine.
// - A leap year occurs on any year evenly divisible by 4, but not on a century
//   unless it is divisible by 400.
//
// How many Sundays fell on the first of the month during the twentieth century
// (1 Jan 1901 to 31 Dec 2000)?
//
// Answer: 171
// Execution time: 0m0.002s

#include <iostream>

using namespace std;

enum
{
  JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC
};

int main()
{
  int days[12];
  days[JAN] = 31; days[FEB] = 28; days[MAR] = 31; days[APR] = 30;
  days[MAY] = 31; days[JUN] = 30; days[JUL] = 31; days[AUG] = 31;
  days[SEP] = 30; days[OCT] = 31; days[NOV] = 30; days[DEC] = 31;

  // Keep track of the day. Sundays are multiples of 7. Initialize to 1 since
  // the first day of 1900 was a Monday.
  int day_tracker = 1;

  int first_sundays = 0;

  for (int year = 1900; year < 2001; ++year)
  {
    for (int month = JAN; month <= DEC; ++month)
    {
      if (day_tracker % 7 == 0 && year > 1900)
        ++first_sundays;

      // Check for leap year
      if (month == FEB && year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
        day_tracker += 29;
      else
        day_tracker += days[month];
    }
  }

  cout << first_sundays << endl;
}
