#include "Vector.h"
#include "Terrain.h"
#include "Node.h"
#include <string>
#include <fstream>
#include <stdlib.h>
#include <iostream>

Terrain::Terrain():longueur(0),largeur(0){}
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
  /*for(int i = 0;i < longueur;i++)
  {
    delete []nodes[i];
  }
  delete []nodes;*/
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
}
Terrain::Terrain(std::string &s)
{
  
  std::ifstream f(s.c_str());
  if(f.is_open())
  {
    std::string l;
    int i = 0;
    int x = 0;
    int y = 0;
    getline(f,l);
    //
    x = l.find_first_of("_",0);
    Spos.x = atoi(l.substr(0,x).c_str());
    y = l.find_first_of("_",x+1);
    Spos.y = atoi(l.substr(x+1,y).c_str());
    x = l.find_first_of("_",y+1);
    Tpos.x = atoi(l.substr(y+1,x).c_str());
    y = l.find_first_of("_",x+1);
    Tpos.y = atoi(l.substr(x+1,y).c_str());

    x = l.find_first_of("_",y+1);
    largeur = atoi(l.substr(y+1,x).c_str());
    y = l.find_first_of("_",x+1);
    longueur = atoi(l.substr(x+1,y).c_str());
    x = 0;
    y = 0;
    //
    while(y < largeur)
    {
      getline(f,l);
      while(l[i] != NULL)
      {
	int val = atoi(l.substr(i,1).c_str());
	if(val != 0)
	{
	  Node::Type t = Node::NONE;
	  char c = l[i+1];
	  nodes[x][y].setPorter(val);
	  i++;
	  switch(c)
	  {
	  case 'e':
	    t = Node::eau;
	    break;
	  case 's':
	    t = Node::sable;
	    break;
	  case 'h':
	    t = Node::herbe;
	    break;
	  }
	  Vector v(x,y);
	  nodes[x][y].setPos(v);
	  nodes[x][y].setType(t);
	}
	i++;
	x++;
      }
      y++;
      i = 0;
      x = 0;
    }
  }
  
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
}
int Terrain::getLon(){ return longueur;}
int Terrain::getLar(){ return largeur;}
Vector& Terrain::getStartPos(){ return Spos;}
Vector& Terrain::getTargetPos(){ return Tpos;}
void Terrain::setLon(int l){ longueur = l;}
void Terrain::setLar(int l){ largeur = l;}
void Terrain::setStartPos(const Vector &v){ Spos = v;}

Node& Terrain::getNode(const Vector &v)
{
  if(v.x < longueur && v.y < largeur)
    return nodes[v.x][v.y];
  else
  {
    Node n;
    return n;
  }
}
