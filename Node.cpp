#include "Vector.h"
#include "Node.h"

Node::Node():type(NONE),porter(0){}
Node::Node(const Vector &v, Type t,int i):pos(v), type(t),porter(i){}
Node::Node(const Node &n):pos(n.pos),type(n.type),porter(n.porter){}
void Node::operator=(const Node &n)
{
  pos = n.pos;
  type = n.type;
  porter = n.porter;
}

Node::Type Node::getType()
{
  return type;
}
Vector Node::getPos()
{
  return pos;
}
int Node::getPorter()
{
  return porter;
}
void Node::setType(Node::Type t)
{
  type = t;
}
void Node::setPos(const Vector &v)
{
  pos = v;
}
void Node::setPorter(int i)
{
  porter = i;
}
