/*
Author: Sarah Khaldi
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 3B

A program that finds the minimum and maximum storage in East basin in 2018.
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
 double min = INT_MAX, max = INT_MIN; // where i will be storing the min and max values
 double eastSt, eastEl, westSt, westEl;
 while (fin >> date >> eastSt >> eastEl >> westSt >> westEl)
 {
  fin.ignore(INT_MAX, '\n');

  if (eastSt > max) // the max is getting updated with every line being read
  {
   max = eastSt;
  }
  if (eastSt < min) // the min is getting updated with every line being read
  {
   min = eastSt;
  }
 }
 cout << "minimum storage in East basin: " << min << endl;
 cout << "MAXimum storage in East basin: " << max << endl;

 fin.close();
 return 0;
}