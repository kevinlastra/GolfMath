#ifndef VECTOR_H
#define VECTOR_H

class Vector
{
 public:
  int x;
  int y;
  Vector();
  Vector(const int,const int);
  Vector(const Vector&);
  void operator=(const Vector&);
  bool operator==(const Vector&);
};

#endif
