/*
Author: Sarah Khaldi
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 4E

This Program prints the top-right half of a square, given the side length.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
 int length;
 cout << "Input side length: ";
 cin >> length;
 cout << "\n"
      << "Shape:" << endl;

 for (int i = 1; i < (length + 1); i++) // for the rows
 {
  cout << setw(i);                       // as the i increases -> it pushes the stars to the left
  for (int j = (length + 1); j > i; j--) // for the decremented stars
  {
   cout << "*";
  } 
  cout << endl;
 }

 return 0;
}