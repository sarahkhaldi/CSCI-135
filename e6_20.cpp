/*
Sarah Khaldi
HW E6.20

Write a function vector<int> merge_sorted(vector<int> a, vector<int> b)
that merges two sorted vectors, producing a new sorted vector. Keep an index into each vector, indicating how much of it has been processed already. Each time, append the smallest unprocessed element from either vector, then advance the index.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> merge_sorted(vector<int> a, vector<int> b)
{
 for (int i = 0; i < b.size(); i++)
 {
  a.push_back(b.at(i));
 }

 for (int i = 1; i < a.size(); i++)
 {
  for (int j = 0; j < i; j++)
  {
   int smallest = a.at(i);
   if (a.at(i) < a.at(j))
   {
    a.at(i) = a.at(j);
    a.at(j) = smallest;
   }
  }
 }
 return a;
}

int main()
{
 vector<int> a{1, 4, 9, 16};
 vector<int> b{4, 7, 9, 9, 11};

 merge_sorted(a, b);
 return 0;
}
