/*
Author: Sarah Khaldi
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 3C

This Program asks the user to input two dates (the beginning and the end of the interval). The program should check each day in the interval and report which basin had higher elevation on that day by printing “East” or “West”, or print “Equal” if both basins are at the same level.
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

 string date_start, date_end; // taking input of the date interval
 cout << "Enter start date: ";
 cin >> date_start;
 cout << "Enter end date: ";
 cin >> date_end;

 string junk;        // new string variable
 getline(fin, junk); // read one line from the file
 string date;
 string dateArr[365];   //   storing  dates into an array
 double eastStArr[365]; // storing data into arrays
 double eastElArr[365]; // storing data into arrays
 double westStArr[365]; // storing data into arrays
 double westElArr[365]; // storing data into arrays
 int size = 0;          // checker for my while loop

 double eastSt, eastEl, westSt, westEl; // *reads* the data from the file only
 while (fin >> date >> eastSt >> eastEl >> westSt >> westEl)
 {
  fin.ignore(INT_MAX, '\n');
  if (size < 365) // use an if statement to store values into arrays
  {
   dateArr[size] = date;
   eastStArr[size] = eastSt;
   eastElArr[size] = eastEl;
   westStArr[size] = westSt;
   westElArr[size] = westEl;
   size++;
  }
 }

 int n = 0;
 while (n < 365)
 {
  if (dateArr[n] == date_start) // checking the start of the interval
  {
   while (dateArr[n] != date_end) // checking the middle of the interval
   {
    if (eastElArr[n] > westElArr[n])
    {
     cout << dateArr[n] << " East" << endl;
    }
    else if (westElArr[n] > eastElArr[n])
    {
     cout << dateArr[n] << " West" << endl;
    }
    else
    {
     cout << dateArr[n] << " Equal" << endl;
    }
    n++;
   }
  }
  if (dateArr[n] == date_end) // checking the end of the interval
  {
   if (eastElArr[n] > westElArr[n])
   {
    cout << dateArr[n] << " East" << endl;
   }
   else if (westElArr[n] > eastElArr[n])
   {
    cout << dateArr[n] << " West" << endl;
   }
   else
   {
    cout << dateArr[n] << " Equal" << endl;
   }
  }
  n++;
 }

 fin.close();

 return 0;
}