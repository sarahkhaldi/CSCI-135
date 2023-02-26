/*
Author: Sarah Khaldi
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 4G

This Program asks the user to input width and height and prints a checkerboard of 3-by-3 squares. (It should work even if the input dimensions are not a multiple of three.)
*/

#include <iostream>
using namespace std;

int main()
{
 int width, height;
 cout << "Input width: ";
 cin >> width;
 cout << "Input height: ";
 cin >> height;
 cout << "Shape:" << endl;

 int counterX = 0; // counter for the height
 int counterY = 0;
 for (int i = 1; i < (height + 1); i++)
 {
  if ((((i % 3) == 0) && ((i / 3) % 2 != 0))) // if i is multiple of 3 and odd
  {
   counterX = counterX + 3;
   for (int j = i; j > (i - 3); j--) // loop for each 3 rows
   {
    counterY = 0;
    for (int x = 1; x < (width + 1); x++)
    {
     if (((x % 3) == 0) && ((x / 3) % 2 != 0)) // width is multiple of 3 and odd
     {
      counterY = counterY + 3;
      for (int y = x; y > (x - 3); y--) // loop for each star width
      {
       cout << "*";
      }
     }
     else if (((x % 3) == 0) && ((x / 3) % 2 == 0)) // width is multiple of 3 and even
     {
      counterY = counterY + 3;
      for (int y = x; y > (x - 3); y--)
      {
       cout << " ";
      }
     }
    }
    if ((width % 3) != 0)
    {
     if (((counterY % 2) != 0)) // width remainder after ODD
     {
      for (int y = 1; y < (width % 3) + 1; y++)
      {
       cout << " ";
      }
     }
     else if (((counterY % 2) == 0)) // width remainder after even
     {
      for (int y = 1; y < (width % 3) + 1; y++)
      {
       cout << "*";
      }
     }
    }
    cout << endl;
   }
  }

  else if (((i % 3) == 0) && ((i / 3) % 2 == 0)) // if i is multiple of 3 and even
  {
   counterX = counterX + 3;
   for (int j = i; j > (i - 3); j--) // loop for each 3 rows
   {
    counterY = 0;
    for (int x = 1; x < (width + 1); x++)
    {
     if (((x % 3) == 0) && ((x / 3) % 2 != 0)) // width is multiple of 3 and odd
     {
      counterY = counterY + 3;
      for (int y = x; y > (x - 3); y--) // loop for each star width
      {
       cout << " ";
      }
     }
     else if (((x % 3) == 0) && ((x / 3) % 2 == 0)) // width is multiple of 3 and even
     {
      counterY = counterY + 3;
      for (int y = x; y > (x - 3); y--)
      {
       cout << "*";
      }
     }
    }
    if ((width % 3) != 0)
    {
     if (((counterY % 2) != 0)) // width remainder after ODD
     {
      for (int y = 1; y < (width % 3) + 1; y++)
      {
       cout << "*";
      }
     }
     else if (((counterY % 2) == 0)) // width remainder after even
     {
      for (int y = 1; y < (width % 3) + 1; y++)
      {
       cout << " ";
      }
     }
    }
    cout << endl;
   }
  }
 }

 // cout << counterX << endl;

 if ((height % 3) != 0)
 {
  if (counterX % 2 != 0) // height remainder after ODD
  {
   // cout << "ON TOP " << height - counterX << endl;
   for (int i = 0; i < height - counterX; i++)
   {
    counterY = 0;
    for (int x = 1; x < (width + 1); x++)
    {
     if (((x % 3) == 0) && ((x / 3) % 2 != 0)) // width is multiple of 3 and odd
     {
      counterY = counterY + 3;
      for (int y = x; y > (x - 3); y--) // loop for each star width
      {
       cout << " ";
      }
     }
     else if (((x % 3) == 0) && ((x / 3) % 2 == 0)) // width is multiple of 3 and even
     {
      counterY = counterY + 3;
      for (int y = x; y > (x - 3); y--)
      {
       cout << "*";
      }
     }
    }
    if ((width % 3) != 0)
    {
     if (((counterY % 2) != 0)) // width remainder after ODD
     {
      for (int y = 1; y < (width % 3) + 1; y++)
      {
       cout << "*";
      }
     }
     else if (((counterY % 2) == 0)) // width remainder after even
     {
      for (int y = 1; y < (width % 3) + 1; y++)
      {
       cout << " ";
      }
     }
     cout << endl;
    }
   }
  }
 }
 if ((counterX) % 2 == 0) // after even
 {
  // cout << "LOOK HERE 1 " << counterX << endl;
  for (int i = 0; i < height - counterX; i++)
  {
   counterY = 0;
   for (int x = 1; x < (width + 1); x++)
   {
    if (((x % 3) == 0) && ((x / 3) % 2 != 0)) // width is multiple of 3 and odd
    {
     counterY = counterY + 3;
     for (int y = x; y > (x - 3); y--) // loop for each star width
     {
      cout << "*";
     }
    }
    else if (((x % 3) == 0) && ((x / 3) % 2 == 0)) // width is multiple of 3 and even
    {
     counterY = counterY + 3;
     for (int y = x; y > (x - 3); y--)
     {
      cout << " ";
     }
    }
   }
   if ((width % 3) != 0)
   {
    if (((counterY % 2) != 0)) // width remainder after ODD
    {
     for (int y = 1; y < (width % 3) + 1; y++)
     {
      cout << " ";
     }
    }
    else if (((counterY % 2) == 0)) // width remainder after even
    {
     for (int y = 1; y < (width % 3) + 1; y++)
     {
      cout << "*";
     }
    }
    cout << endl;
   }
  }
  if ((counterX % 2) != 0) // after ODD
  {
   // cout << "LOOK HERE 2 " << counterX << endl;
   for (int i = 0; i < height - counterX; i++)
   {
    counterY = 0;
    for (int x = 1; x < (width + 1); x++)
    {
     if (((x % 3) == 0) && ((x / 3) % 2 != 0)) // width is multiple of 3 and odd
     {
      counterY = counterY + 3;
      for (int y = x; y > (x - 3); y--) // loop for each star width
      {
       cout << " ";
      }
     }
     else if (((x % 3) == 0) && ((x / 3) % 2 == 0)) // width is multiple of 3 and even
     {
      counterY = counterY + 3;
      for (int y = x; y > (x - 3); y--)
      {
       cout << "*";
      }
     }
    }
    if ((width % 3) != 0)
    {
     if (((counterY % 2) != 0)) // width remainder after ODD
     {
      for (int y = 1; y < (width % 3) + 1; y++)
      {
       cout << " ";
      }
     }
     else if (((counterY % 2) == 0)) // width remainder after even
     {
      for (int y = 1; y < (width % 3) + 1; y++)
      {
       cout << "*";
      }
     }
     cout << endl;
    }
   }
  }
 }

 return 0;
}