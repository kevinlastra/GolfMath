#ifndef TERRAIN_
#define TERRAIN_

#include "Vector.h"
#include "Node.h"
#include <string>

class Terrain
{
 private:
  Node nodes[256][256];
  int longueur;//x
  int largeur;//y
  Vector Spos;
  
 public:
  Terrain();
  Terrain(Node**,int,int,const Vector&);
  Terrain(const Terrain&);
  Terrain(std::string&);
  ~Terrain();
  void operator=(const Terrain&);

  int getLon();
  int getLar();
  Vector& getStartPos();

  void setLon(int);
  void setLar(int);
  void setStartPos(const Vector&);

  Node& getNode(const Vector&);
  
};
#endif
