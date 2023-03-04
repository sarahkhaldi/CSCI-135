/*
Author: Sarah Khaldi
Course: CSCI-135
Instructor: Genady Maryash
Assignment: E6.8

Write a function
bool equals(int a[], int a_size, int b[], int b_size)
that checks whether two arrays have the same elements in the same order.
*/

#include <iostream>
using namespace std;

bool equals(int a[], int a_size, int b[], int b_size)
{
 if (a_size != b_size) // if two arrays are not the same size --> return false
 {
  return false;
 }
 else // if they are the same size --> check if every element is equal on both arrays
 {
  int i = 0;
  while (i < a_size)
  {
   if (a[i] != b[i]) // if an element is different --> return false
   {
    return false;
   }
   i++;
  }
 }
 return true;
}
