/*
Author: Sarah Khaldi
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 6A

Write a program test-ascii.cpp that asks the user to input a line of text (which may possibly include spaces). The program should report all characters from the input line together with their ASCII codes.
*/

#include <iostream>
using namespace std;

int main()
{
 string input;
 cout << "Input: ";
 getline(cin, input); // need getline to read the ENTIRE string --> not just a word
 int lengthInput = input.length();
 for (int i = 0; i < lengthInput; i++) // looping thru the letters
 {
  for (int j = ' '; j < 127; j++) // looping thru ascii characters
  {
   if (input[i] == char(j))
   {
    cout << input[i] << " " << j << endl;
   }
  }
 }
 return 0;
}