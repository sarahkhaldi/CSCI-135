/*
Author: Sarah Khaldi
Course: CSCI-135
Instructor: Genady Maryash
Lab: 12A

For this task, program a function called vector<int> makeVector(int n) that returns a vector of n integers that range from 0 to n-1.
*/

#include <iostream>
#include <vector>
using namespace std;

// creating a vector of type int, takes in n as a param
vector<int> makeVector(int n)
{
 vector<int> v; // initializing the vector
 for (int i = 0; i < n; i++)
 {
  v.push_back(i); // adding elements to the vector
 }
 return v;
}

int main()
{
 makeVector(10);
 return 0;
}