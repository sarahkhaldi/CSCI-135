/*
Author: Sarah Khaldi
Course: CSCI-135
Instructor: Genady Maryash
Lab: 13A
*/

#include <iostream>
using namespace std;

void printRange(int left, int right)
{
 if (left <= right)
 {
  cout << left << " ";
  printRange(left + 1, right);
 }
}

int sumRange(int left, int right)
{
 int sum = 0;
 if (left <= right)
 {
  sum = left + sumRange(left + 1, right);
 }
 return sum;
}

int main()
{
 // printRange(-2, 10);

 int x = sumRange(1, 3);
 cout << "This is " << x << endl; // 6

 int y = sumRange(-2, 10);
 cout << "That is " << y << endl; // 52
 return 0;
}