/*
Author: Sarah Khaldi
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 4D

This Program prints the bottom-left half of a square, given the side length.
*/

#include <iostream>
using namespace std;

int main()
{
 int length;
 cout << "Input side length: ";
 cin >> length;
 cout << "\n"
      << "Shape:" << endl;

 for (int i = 1; i < (length + 1); i++) // for the triangle rows
 {
  for (int j = 0; j < i; j++) // for the triangle columns
  {
   cout << "*";
  }
  cout << endl;
 }

 return 0;
}