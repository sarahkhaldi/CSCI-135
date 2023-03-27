/*
Author: Sarah Khaldi
Course: CSCI-135
Instructor: Genady Maryash
Assignment: E7.1

Write a function
void sort2(double* p, double* q)
that receives two pointers and sorts the values to which they point. If you call 
sort2(&x, &y) then x <= y after the call.
*/

#include <iostream>
using namespace std;

void sort2(double* p, double* q)
{
 if (*p > *q)
 {
  double temp = *p;
  *p = *q;
  *q = temp;
 }
 cout << *p << ", " << *q << '\n';
}

int main()
{
 double x = 10;
 double y = 7;
 sort2(&x, &y);

 return 0;
}