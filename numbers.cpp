/*
Author: Sarah Khaldi
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 5G

This program returns the largest twin prime in the range a ≤ N ≤ b.
*/

#include <iostream>
using namespace std;

bool isDivisibleBy(int n, int d) // defining the function to test DIVISIBILITY
{
 if ((n % d) == 0)
 {
  cout << "Yes" << endl;
  return true;
 }
 else
 {
  cout << "No" << endl;
  return false;
 }
}

bool isPrime(int n) // function to test if a num is a PRIME
{
 for (int i = 2; i < (n / 2) + 1; i++)
 {
  if ((n % i) == 0)
  {
   // cout << "Not a prime" << endl;
   return false;
  }
 }
 // cout << "Prime" << endl;
 return true;
}

int nextPrime(int n) // finding the NEXT PRIME after n
{
 int answerTemp = n + 1; // variable to hold the possible prime number
 int answer;
 bool found = false; // bool value to check if prime is found

 while (!found)
 {
  if (((isPrime(answerTemp)) == true) && (answerTemp > 1)) // referincing the isPrime(n) function to check if answerTemp is prime and poitive
  {
   answer = answerTemp;
   found = true;
  }
  else
  {
   answerTemp++;
  }
 }
 // cout << answer << endl;
 return answer;
}

int countPrimes(int a, int b) // finding the number of prime numbers in a range
{
 int counter = 0; // initializing the counter
 for (int i = a; i < b + 1; i++)
 {
  if (isPrime(i) == true && (i > 1))
  {
   counter++;
  }
 }
 cout << counter << endl;
 return counter;
}

bool isTwinPrime(int n) // finding if prime is a twin prime --> 2 is NOT a twin prime!
{
 if ((isPrime(n) == true) && (n > 2) && ((isPrime(n - 2) == true) || (isPrime(n + 2) == true)))
 {
  // cout << "Twin Prime" << endl;
  return true;
 }
 // cout << "Not a twin prime" << endl;
 return false;
}

int nextTwinPrime(int n) // finding the next twin prime number
{
 int answerTemp = nextPrime(n); // variable holding the temp answer
 int answer;                    // variable holding thr answer
 bool found = false;            // boolean to see if the answer is found
 while (!found)
 {
  if (isTwinPrime(answerTemp) == false)
  {
   answerTemp++;
  }
  else
  {
   answer = answerTemp;
   found = true;
  }
 }
 // cout << answer << endl;
 return answer;
}

int largestTwinPrime(int a, int b) // finding the largest twin prime in a range
{
 int largest = -1; // variable to hold the largest twim prime
 for (int i = b; i >= a; i--)
 {
  if ((nextTwinPrime(i) <= b))
  {
   largest = nextTwinPrime(i);
   return largest;
  }
 }
 return largest;
}

int main()
{
 int num1, num2; // taking in user input for the function
 cout << "Enter first number: ";
 cin >> num1;
 cout << "Enter second number: ";
 cin >> num2;
 // isDivisibleBy(num1, num2); // calling the divisibility function
 // isPrime(num1); // calling the prime function
 // nextPrime(num1); // calling the next prime function
 // countPrimes(num1, num2);
 // isTwinPrime(num1);
 // nextTwinPrime(num1);
 largestTwinPrime(num1, num2);
}
