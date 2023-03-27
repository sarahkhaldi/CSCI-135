/*
Author: Sarah Khaldi
Course: CSCI-135
Instructor: Genady Maryash
Assignment: E7.18

Define a structure Triangle that contains three Point members. Write a function that computes the perimeter of a Triangle. Write a program that reads the coordinates of the points, calls your function, and displays the result.
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

class Triangle
{
 public:
 Point a;
 Point b;
 Point c;
};

double perimeter(Triangle T)
{
 double answer;
 double length1, length2, length3;
 double xSquared1, ySquared1, xSquared2, ySquared2, xSquared3, ySquared3;

 xSquared1 = pow((T.b.x - T.a.x), 2);
 xSquared2 = pow((T.b.x - T.c.x), 2);
 xSquared3 = pow((T.c.x - T.a.x), 2);

 ySquared1 = pow((T.b.y - T.a.y), 2);
 ySquared2 = pow((T.b.y - T.c.y), 2);
 ySquared3 = pow((T.c.y - T.a.y), 2);

 length1 = sqrt(xSquared1 + ySquared1);
 length2 = sqrt(xSquared2 + ySquared2);
 length3 = sqrt(xSquared3 + ySquared3);

 answer = length1 + length2 + length3;
 return answer;
}

int main()
{
 Triangle T = {{10, 10}, {20, 20}, {30, 30}};
 cout << perimeter(T) << endl;

 return 0;
}