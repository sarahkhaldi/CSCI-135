/*
Author: Sarah Khaldi
Course: CSCI-135
Instructor: Genady Maryash
Assignment: E7.16

Define a structure Point. A point has an x-and a y-coordinate. Write a function double distance(Point a, Point b) that computes the distance from a to b. Write a program that reads the coordinates of the points, calls your function, and displays the result.
*/

#include <iostream>
#include <cmath>
using namespace std;

class Point
{
 public:
  double x;
  double y;
};

double distance(Point a, Point b)
{
 double answer;
 double xSquared, ySquared;
 xSquared = pow((b.x - a.x), 2);
 ySquared = pow((b.y - a.y), 2);
 answer = sqrt(xSquared + ySquared);
 return answer;
}

int main()
{
 Point a = {10, 10};
 Point b = {20, 20};
 cout << distance(a, b) << endl;

 return 0;
}