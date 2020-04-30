#ifndef NODE_
#define NODE_

#include "Vector.h"

class Node
{
 public:
  enum Type {eau, sable, herbe, start,end,NONE};
 private:
  Type type;
  Vector pos;
  int porter;
 public:
  Node();
  Node(const Vector&,Type,int);
  Node(const Node&);
  void operator=(const Node&);

  Type getType();
  Vector getPos();
  int getPorter();
  
  void setType(Type);
  void setPos(const Vector&);
  void setPorter(int);
};

#endif
