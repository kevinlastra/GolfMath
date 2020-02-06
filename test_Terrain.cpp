#include <iostream>
#include "Terrain.h"
#include "Node.h"
#include "Vector.h"
#include <string>

void PrintMap(Terrain &t)
{
  std::cout << "Longueur:"<<t.getLon()<<"     Largeur:"<<t.getLar()<<std::endl;
  for(int i = 0; i < t.getLon();i++)
  {
    for(int j = 0; j < t.getLar();j++)
    {
      Vector v(i,j);
      switch(t.getNode(v).getType())
      {
        case Node::herbe:
	  std::cout << "\033[1;32m["<<t.getNode(v).getPorter()<<"]\033[0m";
	  break;
        case Node::sable:
	  std::cout << "\033[1;33m["<<t.getNode(v).getPorter()<<"]\033[0m";
	  break;
        default:
	  std::cout << "\033[1;34m  ~\033[0m";
	  break;
      }
    }
    std::cout << std::endl;
  }
}
int main(int argc, char** argv)
{
  std::string s(argv[1]);
  Terrain T(s);
  PrintMap(T);
  return 0;
}
