#include "Vector.h"

Vector::Vector():x(0),y(0){}
Vector::Vector(const int x_, const int y_):x(x_),y(y_){}
Vector::Vector(const Vector &v):x(v.x),y(v.y){}
void Vector::operator=(const Vector &v)
{
  x = v.x;
  y = v.y;
}
bool Vector::operator==(const Vector &v)
{
  if(x == v.x && y == v.y)
    return true;
  else
    return false;
}
