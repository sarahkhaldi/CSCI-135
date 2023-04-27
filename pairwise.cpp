/*
Author: Sarah Khaldi
Course: CSCI-135
Instructor: Genady Maryash
Lab: 12D

This program implements the function vector<int> sumPairWise(const vector<int> &v1, const vector<int> &v2) that returns a vector of integers whose elements are the pairwise sum of the elements from the two vectors passed as arguments. If a vector has a smaller size than the other, consider extra entries from the shorter vectors as 0.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> sumPairWise(vector<int> &v1, vector<int> &v2)
{
 vector<int> sumPairs;
 // checking if vector sizes are not equal --> append with zeros
 if (v1.size() > v2.size())
 {
  int dif = v1.size() - v2.size();
  for (int i = 0; i < dif; i++)
  {
   v2.push_back(0);
  }
 }
 else if (v1.size() < v2.size())
 {
  int dif = v2.size() - v1.size();
  for (int i = 0; i < dif; i++)
  {
   v1.push_back(0);
  }
 }

 for (int i = 0; i < v1.size(); i++)
 {
  int sum = v1.at(i) + v2.at(i); // adding the sum of the pairwise elements
  sumPairs.push_back(sum);       // appending the sum to the new vector
 }

 return sumPairs;
}

int main()
{
 vector<int> v1{1, 2, 3};
 vector<int> v2{4, 5};

 sumPairWise(v1, v2); // returns [5, 7, 3]
 return 0;
}