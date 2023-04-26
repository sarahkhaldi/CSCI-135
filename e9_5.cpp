/*
Author: Sarah Khaldi
Course: CSCI-135
Instructor: Genady Maryash
Assignment: E9.5

Implement a class Rectangle. Provide a constructor to construct a rectangle with a given width and height, member functions get_perimeter and get_area that compute the perimeter and area, and a member function void resize(double factor) that resizes the rectangle by multiplying the width and height by the given factor.
*/

#include <iostream>
using namespace std;

class Rectangle
{
 private:
  double height;
  double width;

 public:
  Rectangle(double height1, double width1);
  Rectangle();
  double get_perimeter();
  double get_area();
  void resize(double factor);
};

Rectangle::Rectangle(double height1, double width1)
{
 height = height1;
 width = width1;
}

Rectangle::Rectangle()
{
 height = 0;
 width = 0;
}

double Rectangle::get_perimeter()
{
 double perimeter = (2 * height) + (2 * width);
 return perimeter;
}

double Rectangle::get_area()
{
 double area = height * width;
 return area;
}

void Rectangle::resize(double factor)
{
 height = height * factor;
 width = width * factor;
}

int main()
{
 Rectangle r1(13.3, 3.7);
 cout << "Area is: " << r1.get_area() << endl;
 cout << "Perimeter is: "<< r1.get_perimeter() << endl;
 r1.resize(2);
 cout << "New area is: " << r1.get_area() << endl;
 cout << "New perimeter is: " << r1.get_perimeter() << endl;
 return 0;
}