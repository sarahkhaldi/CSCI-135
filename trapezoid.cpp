/*
Author: Sarah Khaldi
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 4F

This Program prints an upside-down TRAPEZOID of given width and height.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
 int width, height;
 cout << "Input width: ";
 cin >> width;
 cout << "Input height: ";
 cin >> height;

 if ((width - (height - 1) <= (width / 2))) // checking if the height is not too big for the width
 {
  cout << "Impossible shape!" << endl;
  exit(0); // terminate the program if height is too big for the width
 }

 cout << "\n"
      << "Shape: " << endl;

 for (int i = 0; i < height; i++) // loop for the height of the trapezoid
 {
  int j = width;
  cout << setw(i + 1); // setting width to increase as i increases
  while (j > (i * 2))  // decreasing j by 2 every round
  {
   cout << "*";
   j--;
  }
  cout << endl;
 }

 return 0;
}