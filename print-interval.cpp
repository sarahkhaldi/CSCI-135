/*
Author: Sarah Khaldi
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 2B

asks the user to input two integers L and U (representing the lower and upper limits of the interval), and print out all integers in the range L ≤ i < U separated by spaces. Notice that we include the lower limit, but exclude the upper limit.
*/

#include <iostream>
using namespace std;

int main()
{
 int L, U;
 cout << "Please enter L: ";
 cin >> L;
 cout << "Please enter U: ";
 cin >> U;
 cout << "\n";

 for (int i = L; i < U; i++)
 {
  cout << i << " ";
 }

 return 0;
}