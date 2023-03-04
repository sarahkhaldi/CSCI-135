/*
Author: Sarah Khaldi
Course: CSCI-135
Instructor: Genady Maryash
Assignment: E5.15

Write a function sort3(int& a ,int& b ,int& c)that swaps its three arguments to arrange them in sorted order.
*/

#include <iostream>
using namespace std;

void sort2(int& a, int& b)
{
 int temp; // creating a variable that will hold the num im swapping --> so that we don't lose it
 if (a > b)
 {
  temp = b;
  b = a;
  a = temp;
 }
}

void sort3(int& a, int& b, int& c)
{
 sort2(a, b);
 int temp1, temp2; // creating a variable that will hold the num im swapping --> so that we don't lose it
 if ((c < a) && (c < b)) // since we're swapping 2 --> we need 2 temps
 {
  temp1 = a;
  temp2 = b;
  a = c;
  b = temp1;
  c = temp2;
 }
 else if (c < b) // swapping 1 --> only need one temp
 {
  temp1 = b;
  b = c;
  c = temp1;
 }
}

int main()
{
 int num1, num2, num3;
 cout << "Enter first number: ";
 cin >> num1;
 cout << "Enter second number: ";
 cin >> num2;
 cout << "Enter third number:";
 cin >> num3;
 sort3(num1, num2, num3);
 return 0;
}