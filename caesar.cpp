/*
Author: Sarah Khaldi
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 6B

Write a program caesar.cpp with functions implementing Caesar cipher encryption.
*/

#include <iostream>
using namespace std;

char shiftChar(char c, int rshift) // shiffting the characters
{
 char ch;
 if ((char(c) >= 65) && (char(c) <= 122)) // checking that we're only shifting LETTERS
 {
  if ((char(c >= 97)) && (char(c) <= 122) && (char(c) + rshift) <= 122) // shifting LOWERCASE letters
  {
   ch = char(c) + rshift;
  }
  else if ((char(c >= 97)) && (char(c) <= 122) && (char(c) + rshift) > 122) // shifting LOWERCASE letters WRAP-AROUND
  {
   ch = char(c) - 26 + rshift;
  }
  else if ((char(c >= 65)) && (char(c) <= 90) && (char(c) + rshift) <= 90) // shiftting UPPERCASE letters
  {
   ch = char(c) + rshift;
  }
  else if ((char(c >= 65)) && (char(c) <= 90) && (char(c) + rshift) > 90) // shiftting UPPERCASE letters WRAP-AROUND
  {
   ch = char(c) - 26 + rshift;
  }
 }
 else
 {
  ch = char(c);
 }

 return ch;
}

// Caesar cipher encryption
string encryptCaesar(string plaintext, int rshift)
{
 string cipher = "";
 for (int i = 0; i < plaintext.length(); i++)
 {
  cipher = cipher + shiftChar(plaintext[i], rshift); // concatenation of the new ciphered string
 }
 // cout << cipher << endl;
 return cipher;
}

int main()
{
 string input;
 cout << "Enter plaintext: ";
 getline(cin, input); // need getline to read the ENTIRE string --> not just a word
 int shift;
 cout << "Enter shift    : ";
 cin >> shift;
 int lengthInput = input.length();
 cout << "Ciphertext     : " << encryptCaesar(input, shift) << endl;
 return 0;
}