#ifndef VECTOR_
#define VECTOR_

class Vector
{
 public:
  int x;
  int y;
  Vector();
  Vector(const int,const int);
  Vector(const Vector&);
  void operator=(const Vector&);
};

#endif
