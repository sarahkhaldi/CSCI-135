/*
Sarah Khaldi
HW E6.18

Write a function vector<int> append(vector<int> a, vector<int> b) that appends one vector after another.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> append(vector<int> a, vector<int> b)
{
 int elementSum = a.size() + b.size();
 for (int i = 0; i < b.size(); i++)
 {
  a.push_back(b.at(i));
 }

 return a;
}

int main()
{
 vector<int> a{1, 2, 3};
 vector<int> b{4, 5, 6};

 append(a, b); 
 return 0;
}
