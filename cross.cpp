/*
Author: Sarah Khaldi
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 4C

This Program asks the user to input the shape size, and prints a diagonal CROSS of that dimension.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
 int size;
 cout << "Input size: ";
 cin >> size;
 cout << "\n"
      << "Shape: " << endl;

 // loop for the upper half of the cross
 for (int i = 1; i <= (size / 2) + 1; i++)
 {
  if ((size % 2) == 0) // if size is even -> print half of rows
  {
   while (i < (size / 2) + 1)
   {
    cout << setw(i) << "*" << setw(((size) + 1) - i * 2) << "*" << endl;
    i++;
   }
  }

  else if (((size % 2) != 0) && (i == (size / 2) + 1)) // printing the center star for an odd size
  {
   cout << setw(i) << "*" << endl;
  }
  else // if size is odd -> print half + 1
  {
   cout << setw(i) << "*" << setw(((size) + 1) - i * 2) << "*" << endl;
  }
 }

 // loop for the lower half of the cross
 for (int i = (size / 2); i > 0; i--)
 {
  // you dont need to mess with the lower part of the cross :)
  cout << setw(i) << "*" << setw(((size) + 1) - i * 2) << "*" << endl;
 }

 return 0;
}
