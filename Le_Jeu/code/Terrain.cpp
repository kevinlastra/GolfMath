#include "Vector.h"
#include "Terrain.h"
#include "Node.h"
#include <string>
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <cmath>

Terrain::Terrain(Node** ns, int lo, int la, const Vector &v):longueur(lo), largeur(la), Spos(v)
{
  for(int i = 0; i < largeur;i++)
  {
    for(int j = 0;j < longueur;j++)
    {
      nodes[i][j] = ns[i][j];
    }
  }
}
Terrain::Terrain(const Terrain &t):nodes(t.nodes), longueur(t.longueur), largeur(t.largeur), Spos(t.Spos){}
Terrain::~Terrain()
{
  delete []nodes;
}
void Terrain::operator=(const Terrain &t)
{
  for(int i = 0; i < t.largeur;i++)
  {
    for(int j = 0;j < t.longueur;j++)
    {
      nodes[i][j] = t.nodes[i][j];
    }
  }
  longueur = t.longueur;
  largeur = t.largeur;
  Spos = t.Spos;
  Tpos = t.Tpos;
}
Terrain::Terrain(int seed_, Vector dim, int nbMove, int marge)
{
  longueur = dim.x;
  largeur = dim.y;

  int bone[] = {8,8,7,6,5,4,3,2,2};
  int SX[nbMove];
  int SY[nbMove];
  int trynumber = 0;
  seed = seed_;
  if(seed == -1)
    seed = time(NULL);
  srand(seed);

  bool truedraw = true;

  while(truedraw)
  {
    trynumber++;
    int compt = 15;

    //init
    InitTab(Vector(longueur,largeur));

    int i = nbMove-1;
    //start point
    int tx = rand()%(longueur/2);
    int ty = rand()%(largeur/2);
    //last
    int lastdir = 10;
    float lastdist = 0;
    int lastI = 9;
    SX[i] = tx;
    SY[i] = ty;
    i--;
    while(i >= 0)
    {
      if(i == lastI)
    compt--;
      if(compt == 0)
    break;
      lastI = i;
      int direction = rand()%8;
      int dist_ = bone[8-i]+(rand()%3)-1;
      int px = SX[i+1];
      int py = SY[i+1];

      if((9-direction) == lastdir)
      continue;
      switch(direction)
      {
      case 1:
    px -= dist_;
    py += dist_;
    break;
      case 2:
    py += dist_;
    break;
      case 3:
    px += dist_;
    py += dist_;
    break;
      case 4:
    px -= dist_;
    break;
      case 5:
    px += dist_;
    break;
      case 6:
    px -= dist_;
    py -= dist_;
    break;
      case 7:
    py -= dist_;
    break;
      case 8:
    px += dist_;
    py -= dist_;
    break;
      default:
    continue;
      }
      if(px > marge && px < longueur-marge && py > marge
     && py < largeur-marge && nodes[px][py].getPorter() == 0
     && dist(px-tx,py-ty) > lastdist)
      {
    Vector v(SX[i+1],SY[i+1]);
    nodes[v.x][v.y].setPorter(dist_);
    nodes[v.x][v.y].setType(Node::herbe);
    SX[i] = px;
    SY[i] = py;
    i--;
    lastdist = dist(px-tx,py-ty);
    lastdir = direction;
    if(i == -1)
      truedraw = false;
      }
    }
  }
  Tpos = Vector(SX[0],SY[0]);
  Spos = Vector(SX[nbMove-1],SY[nbMove-1]);

  Vector ext = findextrem(Vector(SX[0],SY[0]),SX,SY,nbMove);

  for(int x = 0; x < longueur;x++)
  {
    for(int y = 0; y < largeur;y++)
    {
      if(inRadius(SX,SY,nbMove,Vector(x,y)))
      {
    if(nodes[x][y].getPorter() == 0)
    {
      nodes[x][y].setPorter(GetPortee(Vector(SX[0],SY[0]),Vector(x,y),Vector(SX[0],SY[0]),ext));
      nodes[x][y].setType(Node::herbe);
    }
      }
      else
    nodes[x][y].setType(Node::eau);
    }
  }
  SetEndandStart();
  std::cout<<"generation correcte"<<std::endl;
}
int Terrain::getLon(){ return longueur;}
int Terrain::getLar(){ return largeur;}
int Terrain::getseed(){ return seed;}
Vector& Terrain::getStartPos(){ return Spos;}
Vector& Terrain::getTargetPos(){ return Tpos;}
void Terrain::setLon(int l){ longueur = l;}
void Terrain::setLar(int l){ largeur = l;}
void Terrain::setStartPos(const Vector &v){ Spos = v;}

Node* Terrain::getNode(const Vector &v)
{
  if(v.x < longueur && v.y < largeur && v.x >= 0 && v.y >= 0)
    return &nodes[v.x][v.y];
  else
  {
    return NULL;
  }
}
//Generator
bool Terrain::inRadius(int *SX,int *SY, int nbMove,Vector pos)
{
  for(int i = 1; i < nbMove-1;i++)
  {
    int max;
    if(SX[i] == SX[i+1])
      max = abs(SY[i] - SY[i+1]);
    else
      max = abs(SX[i] - SX[i+1]);
    if(dist(pos.x-SX[i],pos.y-SY[i]) < max)
    {
      return true;
    }
  }
  if(dist(pos.x-SX[nbMove-1],pos.y-SY[nbMove-1]) < 9
     || dist(pos.x-SX[0],pos.y-SY[0]) < 9)
  {
    return true;
  }
  return false;
}
float Terrain::dist(float a, float b)
{
  return sqrt(a*a+b*b);
}
Vector Terrain::findextrem(Vector pos, int *SX, int *SY, int nbMove)
{
  Vector v;
  float maxdist = 0;
  for(int x = 0; x < longueur;x++)
  {
    for(int y = 0;y < largeur;y++)
    {
      float d = dist(x-pos.x,y-pos.y);
      if(d > maxdist && inRadius(SX,SY,nbMove,Vector(x,y)))
      {
    maxdist = d;
    v.x = x;
    v.y = y;
      }
    }
  }
  return v;
}
int Terrain::GetPortee(Vector end,Vector pos,Vector epos,Vector extrem)
{
  float dist_ = dist(epos.x-pos.x,epos.y-pos.y);

  float space = dist(end.x-extrem.x,end.y-extrem.y)+1;

  int portee = (2+(int)((dist_*8)/space)%8) + ((rand()%5)-2)%2;
  if(portee > 9)
    return 9;
  else if(portee < 1)
    return 1;
  else
    return portee;
}
void Terrain::InitTab(Vector dim)
{
  for(int x = 0; x < dim.x;x++)
  {
    for(int y = 0; y < dim.y;y++)
    {
      nodes[x][y].setPorter(0);
      nodes[x][y].setPos(Vector(x,y));
      nodes[x][y].setType(Node::NONE);
    }
  }
}
void Terrain::SetEndandStart()
{
  nodes[Spos.x-1][Spos.y-1].setType(Node::start);
  nodes[Spos.x-1][Spos.y].setType(Node::start);
  nodes[Spos.x-1][Spos.y+1].setType(Node::start);
  nodes[Spos.x][Spos.y-1].setType(Node::start);
  nodes[Spos.x][Spos.y].setType(Node::start);
  nodes[Spos.x][Spos.y+1].setType(Node::start);
  nodes[Spos.x+1][Spos.y-1].setType(Node::start);
  nodes[Spos.x+1][Spos.y].setType(Node::start);
  nodes[Spos.x+1][Spos.y+1].setType(Node::start);

  nodes[Tpos.x][Tpos.y].setType(Node::end);
  nodes[Tpos.x][Tpos.y].setPorter(1);

  nodes[Tpos.x-1][Tpos.y-1].setPorter(1);
  nodes[Tpos.x][Tpos.y-1].setPorter(1);
  nodes[Tpos.x+1][Tpos.y-1].setPorter(1);
  nodes[Tpos.x-1][Tpos.y].setPorter(1);
  nodes[Tpos.x+1][Tpos.y].setPorter(1);
  nodes[Tpos.x-1][Tpos.y+1].setPorter(1);
  nodes[Tpos.x][Tpos.y+1].setPorter(1);
  nodes[Tpos.x+1][Tpos.y+1].setPorter(1);

  nodes[Tpos.x-1][Tpos.y-1].setType(Node::sable);
  nodes[Tpos.x][Tpos.y-1].setType(Node::sable);
  nodes[Tpos.x+1][Tpos.y-1].setType(Node::sable);
  nodes[Tpos.x-1][Tpos.y].setType(Node::sable);
  nodes[Tpos.x+1][Tpos.y].setType(Node::sable);
  nodes[Tpos.x-1][Tpos.y+1].setType(Node::sable);
  nodes[Tpos.x][Tpos.y+1].setType(Node::sable);
  nodes[Tpos.x+1][Tpos.y+1].setType(Node::sable);
}
