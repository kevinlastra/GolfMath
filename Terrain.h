#ifndef TERRAIN_H
#define TERRAIN_H

#include "Vector.h"
#include "Node.h"
#include <string>

class Terrain
{
 private:
  Node nodes[256][256];
  int longueur;//x
  int largeur;//y
  Vector Spos;//start position
  Vector Tpos;//target position
 public:
  Terrain(Node**,int,int,const Vector&);
  Terrain(const Terrain&);
  Terrain(std::string&);
  Terrain(int,Vector,int,int);
  ~Terrain();
  void operator=(const Terrain&);

  int getLon();
  int getLar();
  Vector& getStartPos();
  Vector& getTargetPos();
  
  void setLon(int);
  void setLar(int);
  void setStartPos(const Vector&);

  Node* getNode(const Vector&);

  //Generator
  bool inRadius(int*,int*,int,Vector);
  float dist(float,float);
  Vector findextrem(Vector,int*,int*,int);
  int GetPortee(Vector,Vector,Vector,Vector);
  void InitTab(Vector);
  void SetEndandStart();
};
#endif
