/*
Author: Sarah Khaldi
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 3D

This Program asks the user to input two dates (earlier date then later date). The program should report the West basin elevation for all days in the interval in the reverse chronological order (from the later date to the earlier).
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
 cout << "Enter earlier date: ";
 cin >> date_start;
 cout << "Enter later date: ";
 cin >> date_end;

 string junk;        // new string variable
 getline(fin, junk); // read one line from the file
 string date;
 string dateArr[365];   // storing  dates into an array
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

 int n = 365;
 while (n > 0) // flipping the comparison for the reverse chronological order
 {
  if (dateArr[n] == date_end) // checking the END of the interval
  {
   while (dateArr[n] != date_start) // checking the middle of the interval
   {
    cout << dateArr[n] << " " << westElArr[n] << " ft" << endl;
    n--; // decrementing the counter for the reverse chonological printing
   }
  }
  if (dateArr[n] == date_start) // checking the START of the interval
  {
   cout << dateArr[n] << " " << westElArr[n] << " ft" << endl;
  }
  n--; // decrementing the counter for the reverse chonological printing
 }

 fin.close();

 return 0;
}