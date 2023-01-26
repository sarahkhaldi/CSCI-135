/*
Author: Sarah Khaldi
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab1A

A program that asks the user to input two integer numbers and prints out the smaller of the two
*/

#include <iostream>
using namespace std;

int main()
{
 int num1, num2;
 cout << "Enter the first number: ";
 cin >> num1;
 cout << "Enter the second number: ";
 cin >> num2;

 if (num1 > num2)
 {
  cout << "The smaller of the two is " << num2 << endl;
 }
 else
 {
  cout << "The smaller of the two is " << num1 << endl;
 }

 return 0;
}