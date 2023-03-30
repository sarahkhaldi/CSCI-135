/*
Author: Sarah Khaldi
Course: CSCI-135
Instructor: Genady Maryash
Assignment: 9C

This program gets the position and the velocity of an object and has to compute object’s new coordinates after the time interval dt
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
{
     double answer;
     double xSquared, ySquared, zSquared;
     xSquared = pow((p->x), 2);
     ySquared = pow((p->y), 2);
     zSquared = pow((p->z), 2);
     answer = sqrt(xSquared + ySquared + zSquared);
     return answer;
}

Coord3D *fartherFromOrigin(Coord3D *p1, Coord3D *p2)
{
     if (length(p1) > length(p2))
     {
          return p1;
     }
     else
     {
          cout << length(p2) << endl;
          return p2;
     }
}

void move(Coord3D *ppos, Coord3D *pvel, double dt) // function to find the object’s new position after the elapsed time dt
{
     ppos->x = ppos->x + pvel->x * dt;
     ppos->y = ppos->y + pvel->y * dt;
     ppos->z = ppos->z + pvel->z * dt;
}

// allocate memory and initialize
Coord3D *createCoord3D(double x, double y, double z)
{
     Coord3D *newP = new Coord3D;
     newP->x = x;
     newP->y = y;
     newP->z = z;
     return newP;
}

// free memory
void deleteCoord3D(Coord3D *p)
{
     delete p;
     p = nullptr; // to avoid dangling pointer
}

int main()
{
     Coord3D pointP = {10, 20, 30};
     Coord3D pointQ = {-20, 21, -22};
     // cout << length(&pointP) << endl; // would print 37.4166

     cout << "Address of P: " << &pointP << endl;
     cout << "Address of Q: " << &pointQ << endl
          << endl;

     Coord3D *ans = fartherFromOrigin(&pointP, &pointQ);
     // cout << "ans = " << ans << endl; // would print the address of p1

     Coord3D pos = {0, 0, 100.0};
     Coord3D vel = {1, -5, 0.2};
     move(&pos, &vel, 2.0); // object pos gets changed
     // cout << pos.y << " " << pos.z << endl; // would print: -10 100.4

     double x, y, z;
     cout << "Enter position: ";
     cin >> x >> y >> z;
     Coord3D *ppos = createCoord3D(x, y, z);

     cout << "Enter velocity: ";
     cin >> x >> y >> z;
     Coord3D *pvel = createCoord3D(x, y, z);

     move(ppos, pvel, 10.0);

     cout << "Coordinates after 10 seconds: "
          << (*ppos).x << " " << (*ppos).y << " " << (*ppos).z << endl;

     deleteCoord3D(ppos); // release memory
     deleteCoord3D(pvel);

     return 0;
}