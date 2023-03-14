/*
Author: Sarah Khaldi
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 6D

Write a program decryption.cpp, decryption for both Caesar and Vigerene Ciphers.
*/

#include <iostream>
using namespace std;

char shiftChar(char c, int rshift) // shiffting the characters to a ciphere
{
 if (islower(c))
 {
  c = ((c - 'a' + rshift) % 26) + 'a';
 }
 else
 {
  c = ((c - 'A' + rshift) % 26) + 'A';
 }
 return c;
}

string encryptCaesar(string plaintext, int rshift) // Caesar Cipher
{
 string ciphered = ""; // string to hold the ciphered phrase
 for (int i = 0; i < plaintext.length(); i++)
 {
  if (isalpha(plaintext[i]))
  {
   ciphered = ciphered + shiftChar(plaintext[i], rshift);
  }
  else
  {
   ciphered = ciphered + plaintext[i];
  }
 }
 return ciphered;
}

string encryptVigenere(string plaintext, string keyword) // Vigerene Cipher
{
 string ciphered = ""; // string to hold the ciphered phrase
 int index = 0;
 for (int i = 0; i < plaintext.length(); i++)
 {
  if (isalpha(plaintext[i]))
  {
   ciphered += shiftChar(plaintext[i], keyword[index] - 97);
   index++;
  }
  else
  {
   ciphered = ciphered + plaintext[i];
  }
  if (index == keyword.length())
  {
   index = 0;
  }
 }
 return ciphered;
}

char decrypter(char c, int rshift) // decrypter for caesar and vigenere
{
 int lshift = 26 - rshift;
 if (islower(c))
 {
  c = ((c - 'a' + lshift) % 26) + 'a';
 }
 else
 {
  c = ((c - 'A' + lshift) % 26) + 'A';
 }
 return c;
}

string decryptCaesar(string ciphertext, int lshift) // Caesae Decrypter
{
 ciphertext = encryptCaesar(ciphertext, lshift);
 string plaintext = ""; // the original plain text
 for (int i = 0; i < ciphertext.length(); i++)
 {
  if (isalpha(ciphertext[i]))
  {
   plaintext = plaintext + decrypter(ciphertext[i], lshift);
  }
  else
  {
   plaintext = plaintext + ciphertext[i];
  }
 }
 return plaintext;
}

string decryptVigenere(string ciphertext, string keyword) // Vigerene Decrypter
{
 ciphertext = encryptVigenere(ciphertext, keyword);
 string plaintext = ""; // the original plain text
 int index = 0;
 for (int i = 0; i < ciphertext.length(); i++)
 {
  if (isalpha(ciphertext[i]))
  {
   plaintext += decrypter(ciphertext[i], keyword[index] - 97);
   index++;
  }
  else
  {
   plaintext = plaintext + ciphertext[i];
  }
  if (index == keyword.length())
  {
   index = 0;
  }
 }
 return plaintext;
}

int main()
{
 string input;
 cout << "Enter plaintext: ";
 getline(cin, input); // need getline to read the ENTIRE string --> not just a word
 cout << "= Caesar =" << endl;
 int shift1;
 cout << "Enter shift    : ";
 cin >> shift1; // ceaser shift that is an int
 cout << "Ciphertext     : " << encryptCaesar(input, shift1) << endl;
 cout << "Decrypted      : " << decryptCaesar(input, shift1) << endl;
 cout << "\n";
 string shift2; // vigerene shift that is a string
 cout << "= Vigenere =" << endl;
 cout << "Enter keyword  : ";
 cin >> shift2;
 cout << "Ciphertext     : " << encryptVigenere(input, shift2) << endl;
 cout << "Decrypted      : " << decryptVigenere(input, shift2) << endl;
 return 0;
}
