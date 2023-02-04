/*
Author: Sarah Khaldi
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 2A

This program asks the user to input an integer in the range 0 < n < 100. If the number is out of range, the program should keep asking to re-enter until a valid number is input.
*/

#include <iostream>
using namespace std;

int main()
{
 int input;
 cout << "Please enter an integer: ";
 cin >> input;

 while ((input <= 0) || (input >= 100))
 {
  cout << "Please re-enter: ";
  cin >> input;
 }

 cout << "Number squared is " << input * input << endl;

 return 0;
}