/*
Author: Sarah Khaldi
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 3A

A program that asks the user to input a string representing the date (in MM/DD/YYYY format), and prints out the East basin storage on that day.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
using namespace std;

int main()
{
 ifstream fin("Current_Reservoir_Levels.tsv");
 if (fin.fail())
 {
  cerr << "File cannot be opened for reading." << endl;
  exit(1); // exit if failed to open the file
 }

 string junk;        // new string variable
 getline(fin, junk); // read one line from the filex

 string date;
 double eastSt, eastEl, westSt, westEl;

 string input_date;
 cout << "Enter a date: ";
 cin >> input_date;

 while (fin >> date >> eastSt >> eastEl >> westSt >> westEl) // reads the file line-by-line extracting 5 values on each iteration
 {
  fin.ignore(INT_MAX, '\n'); // skips to the end of line, ignorring the remaining columns
  if (input_date == date)
  {
   cout << "East basin storage: " << eastSt << " billion gallons" << endl;
  }
 }
 fin.close();
 return 0;
}