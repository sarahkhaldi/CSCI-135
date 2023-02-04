/*
Author: Sarah Khaldi
Course: CSCI-135
Instructor: Genady Maryash
Assignment: E1.7

A program that prints three items,such as the names of your three best friends or favorite movies, on three separate lines.
*/

#include <iostream>
using namespace std;

int main()
{
 string item1, item2, item3;
 cout << "Enter 3 things: ";
 cin >> item1 >> item2 >> item3;

 cout << item1 << endl;
 cout << item2 << endl;
 cout << item3 << endl;

 return 0;
}