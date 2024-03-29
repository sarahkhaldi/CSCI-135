/*
Author: Sarah Khaldi
Course: CSCI-135
Instructor: Genady Maryash
Lab: 13E
*/

#include <iostream>
#include <cctype>
#include <string>
using namespace std;

void printRange(int left, int right)
{
 if (left <= right)
 {
  cout << left << " ";
  printRange(left + 1, right);
 }
}

int sumRange(int left, int right)
{
 int sum = 0;
 if (left <= right)
 {
  sum = left + sumRange(left + 1, right);
 }
 return sum;
}

int sumArray(int *arr, int size)
{
 int sum = 0;
 int i = 0;
 if (i < size)
 {
  sum = *arr + sumArray(arr + 1, size - 1); // *arr = 12 and *arr + 1 = 17
                                            // this will call the elements starting from the last one
  i++;
 }
 return sum;
}

bool isAlphanumeric(string s)
{
 if (s.length() == 0)
 {
  return true;
 }
 return (isalpha(s[0]) || isdigit(s[0])) && isAlphanumeric(s.substr(1));
}

bool nestedParens(string s)
{
 if (s.length() == 0)
 {
  return true; // string is empty
 }
 if (s.length() < 2)
 {
  return false; // string too short
 }
 if ((s.length() % 2) != 0)
 {
  return false; // string is not even length
 }
 return ((int(s[0]) == (s[(s.length() - 1)]) - 1) && nestedParens(s.substr(1, s.size() - 2)));
}

int main()
{
 printRange(-2, 10); // -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10

 int x = sumRange(1, 3);
 cout << "This is " << x << endl; // 6

 int y = sumRange(-2, 10);
 cout << "That is " << y << endl; // 52

 int size = 10;
 int *arr = new int[size]; // allocate array dynamically
 arr[0] = 12;
 arr[1] = 17;
 arr[2] = -5;
 arr[3] = 3;
 arr[4] = 7;
 arr[5] = -15;
 arr[6] = 27;
 arr[7] = 5;
 arr[8] = 13;
 arr[9] = -21;

 int sum1 = sumArray(arr, size);    // Add all elements
 cout << "Sum is " << sum1 << endl; // Sum is 43

 int sum2 = sumArray(arr, 5);       // Add up first five elements
 cout << "Sum is " << sum2 << endl; // Sum is 34

 delete[] arr; // deallocate it

 cout << isAlphanumeric("ABCD") << endl;        // true (1)
 cout << isAlphanumeric("Abcd1234xyz") << endl; // true (1)
 cout << isAlphanumeric("KLMN 8-7-6") << endl;  // false (0)

 cout << nestedParens("((()))") << endl; // true (1)
 cout << nestedParens("()") << endl;     // true (1)
 cout << nestedParens("") << endl;       // true (1)

 cout << nestedParens("(((") << endl;   // false (0)
 cout << nestedParens("(()") << endl;   // false (0)
 cout << nestedParens(")(") << endl;    // false (0)
 cout << nestedParens("a(b)c") << endl; // false (0)

 return 0;
}