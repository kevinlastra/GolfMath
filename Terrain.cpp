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
  for(int i = 0; i < largeur;i++)
  {
    for(int j = 0;j < longueur;j++)
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
    int imax;
    int x = 0;
    int y = 0;
    while(!f.eof())
    {
      getline(f,l);
      //std::cout << "line:"<<l<<std::endl;
      while(l[i] != NULL)
      {
	
	int val = atoi(l.substr(i,1).c_str());
	//std::cout << "l["<<i<<"]:"<< l[i] << "    val="<<val<<"      "<<l.substr(i,1).c_str()<<std::endl;
	if(val != 0)
	{
	  char c = l[i+1];
	  Node::Type t = Node::NONE;
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
	  nodes[x][y].setPorter(val);
	  //std::cout << "node["<<i<<","<<y<<"]:"<<nodes[i][y].getPorter()<<std::endl;
	  i++;
	}
	i++;
	x++;
	if(l[i+1]==NULL)
	  imax = i;
      }
      y++;
      i = 0;
      x = 0;
    }
    largeur = y;
    longueur = imax;
  }
}
int Terrain::getLon(){ return longueur;}
int Terrain::getLar(){ return largeur;}
Vector& Terrain::getStartPos(){ return Spos;}

void Terrain::setLon(int l){ longueur = l;}
void Terrain::setLar(int l){ largeur = l;}
void Terrain::setStartPos(const Vector &v){ Spos = v;}

Node& Terrain::getNode(const Vector &v)
{
  if(v.x < longueur && v.y < largeur)
    return nodes[v.y][v.x];
  else
  {
    Node n;
    return n;
  }
}
