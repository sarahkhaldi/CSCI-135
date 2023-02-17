/*
Author: Sarah Khaldi
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 4A

This Program asks the user to input width and height and prints a solid RECTANGULAR BOX of the requested size using asterisks.
*/

#include <iostream>
using namespace std;

int main()
{
 int width, height;
 cout << "Input width: ";
 cin >> width;
 cout << "Input height: ";
 cin >> height;
 cout << "\n";
 cout << "Shape:" << endl;

 for (int i = 0; i < height; i++) // loop for the height
 {
  for (int j = 0; j < width; j++) // loop for the width
  {
   cout << "*";
  }
  cout << endl; // ending the line for each width iteration
 }

 return 0;
}