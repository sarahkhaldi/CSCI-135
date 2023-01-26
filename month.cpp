/*
Author: Sarah Khaldi
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab1D

A program that asks the user to input the year and the month (1-12) and prints the number of days in that month (taking into account leap years).
*/

#include <iostream>
using namespace std;

int main()
{
 int year, month;
 int leap = 0;
 int common = 1;

 cout << "Enter year: ";
 cin >> year;
 cout << "Enter month: ";
 cin >> month;

 if (year % 4 != 0)
 {
  year = common;
 }
 else if (year % 100 != 0)
 {
  year = leap;
 }
 else if (year % 400 != 0)
 {
  year = common;
 }
 else
 {
  year = leap;
 }
 if ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12))
 {
  cout << 31 << " days" << endl;
 }
 else if ((month == 4) || (month == 6) || (month == 9) || (month == 11))
 {
  cout << 30 << " days" << endl;
 }
 else if ((year == 0) && (month == 2)) // leap feb
 {
  cout << 29 << " days" << endl;
 }
 else // common feb
 {
  cout << 28 << " days" << endl;
 }

 return 0;
}