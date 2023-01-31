/*
Author: Sarah Khaldi
Course: CSCI-135
Instructor: Genady Maryash
Assignment: E2.10

A program that asks the user to input:
• The number of gallons of gas in the tank
• The fuel efficiency in miles per gallon
• The price of gas per gallon
Then print the cost per 100 miles and how far the car can go with the gas in the tank.
*/

#include <iostream>
using namespace std;

int main()
{
 float gallon, mpg, price;
 cout << "Enter number of gallons: ";
 cin >> gallon;
 cout << "Enter the fuel efficiency in miles per gallon: ";
 cin >> mpg;
 cout << "Enter the price of gas per gallon: ";
 cin >> price;

 cout << "The cost per 100 miles is " << (100 / mpg) * price << endl;

 cout << "The miles per hour a car can go is " << mpg * gallon << endl;

 return 0;
}
