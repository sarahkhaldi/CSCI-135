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

int main()
{
 printRange(-2, 10);
 return 0;
}