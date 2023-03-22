/*
Author: Sarah Khaldi
Course: CSCI-135
Instructor: Genady Maryash
Assignment: 9A

This program computes the length of a vector containing x, y, and z coordinates.
*/

#include <iostream>
#include <cmath>
using namespace std;

class Coord3D
{
public: // public keyword specifies that those members are accessible from any function
 double x;
 double y;
 double z;
};

double length(Coord3D *p)
{ double answer;
 double xSquared, ySquared, zSquared;
 xSquared = pow((p->x), 2);
 ySquared = pow((p->y), 2);
 zSquared = pow((p->z), 2);
 answer = sqrt(xSquared + ySquared + zSquared);
 return answer;
}

int main()
{
 Coord3D pointP = {10, 20, 30};
 cout << length(&pointP) << endl; // would print 37.4166
 return 0;
}