/*
Author: Sarah Khaldi
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 2C

This program that creates an array of 10 integers, and provides the user with an interface to edit any of its elements.
*/

#include <iostream>
using namespace std;

int main()
{
 int myData[10];
 for (int i = 0; i < 10; i++)
 {
  myData[i] = 1;
 }

 int index, value;
 do
 {
  cout << "\n";
  for (int i = 0; i < 10; i++)
  {
   cout << myData[i] << " ";
  }
  cout << endl;
  cout << "\n";
  cout << "Input index: ";
  cin >> index;
  cout << "Input value: ";
  cin >> value;

  if ((index >= 0) && (index < 10))
  {
   myData[index] = value;
  }

 } while ((index >= 0) && (index < 10));

 cout << "\n";
 cout << "Index out of range. Exit. " << endl;

 return 0;
}