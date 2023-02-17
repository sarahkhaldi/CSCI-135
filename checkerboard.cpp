/*
Author: Sarah Khaldi
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 4B

This Program asks the user to input width and height and prints a rectangular checkerboard of the requested size using asterisks and spaces (ALTERNATING).
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
   if (((width % 2) == 0) && ((i % 2) == 0)) // width is even + height is even
   {
    while ((j < (width / 2)))
    {
     cout << "* ";
     j++;
    }
   }
   else if (((width % 2) != 0) && ((i % 2) == 0)) // width is odd + height is even
   {
    while (j < ((width / 2) + 1))
    {
     cout << "* ";
     j++;
    }
   }
   else if (((width % 2) == 0) && ((i % 2) != 0)) // width is even + height is odd
   {
    while ((j < (width / 2)))
    {
     cout << " *";
     j++;
    }
   }
   else if (((width % 2) != 0) && ((i % 2) != 0)) // width is odd + height is odd
   {
    while ((j < (width / 2)))
    {
     cout << " *";
     j++;
    }
   }
  }
  cout << endl; // ending the line for each width iteration
 }
 return 0;
}
