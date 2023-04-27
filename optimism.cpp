/*
Author: Sarah Khaldi
Course: CSCI-135
Instructor: Genady Maryash
Lab: 12B

This program implements the function vector<int> goodVibes(const vector<int>& v); that, given a vector of integers, returns a vector with only the positive integers in the same order.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> goodVibes(const vector<int> v)
{
 vector<int> newV; // vector to hold only positive ints
 for (int i = 0; i < v.size(); i++)
 {
  if (v.at(i) > 0)
  {
   int num = v.at(i);   // storing the pos value in a temp val
   newV.push_back(num); // storing pos val in the vector
  }
 }
 return newV;
}

int main()
{
 vector<int> v{1, 2, -1, 3, 4, -1, 6};
 goodVibes(v); // returns [1,2,3,4,6]
 return 0;
}