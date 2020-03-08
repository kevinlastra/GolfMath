#include "Vector.h"
#include "Node.h"

Node::Node():type(NONE),porter(0){}
Node::Node(const Vector &v, Type t,int i) :  type(t), pos(v), porter(i){}
Node::Node(const Node &n) : type(n.type), pos(n.pos), porter(n.porter){}
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
void Node::setType(Type t)
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
