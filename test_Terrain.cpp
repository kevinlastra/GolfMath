#include <iostream>
#include "Terrain.h"
#include "Node.h"
#include "Vector.h"
#include <string>

void PrintMap(Terrain &t)
{
  for(int i = 0; i < t.getLon();i++)
  {
    for(int j = 0; j < t.getLar();j++)
    {
      Vector v(i,j);
      if(t.getNode(v).getType() == Node::herbe)
	std::cout << " @";
      else
	std::cout << " 0";
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
