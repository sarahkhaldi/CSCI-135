/*
Author: Sarah Khaldi
Course: CSCI-135
Instructor: Genady Maryash
Lab: 12C

This program implements the function void gogeta(vector<int> &goku, vector<int> &vegeta) that appends elements of the second vector into the first and empties the second vector.
*/

#include <iostream>
#include <vector>
using namespace std;

void gogeta(vector<int> &goku, vector<int> &vegeta)
{
 for (int i = 0; i < vegeta.size(); i++)
 {
  // appending vegeta element to goku
  int num = vegeta.at(i);
  goku.push_back(num);
 }
 vegeta.clear(); // deleting the vector element from vegeta
}

int main()
{
 vector<int> v1{1, 2, 3};
 vector<int> v2{4, 5};
 gogeta(v1, v2); // v1 is now [1,2,3,4,5] and v2 is empty.
 return 0;
}