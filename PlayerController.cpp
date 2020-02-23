#include "PlayerController.h"
#include <iostream>


PlayerController::PlayerController()
{
  pos = Vector(0,0);
  typeJ = H;
  nbcoup = 0;
}
PlayerController::PlayerController(TypeJ t):nbcoup(0)
{
  pos = Vector(0,0);
  typeJ = t;
  nbcoup = 0;
}
PlayerController::PlayerController(Vector &v,TypeJ t):nbcoup(0)
{
  pos = v;
  typeJ = t;
  nbcoup = 0;
}
Vector& PlayerController::GetPos()
{
  return pos;
}
void PlayerController::SetPos(Vector& v)
{
  pos.x = v.x;
  pos.y = v.y;
}
void PlayerController::SetPosAtTerrain(Vector &v)
{
  Vector npos;
  if (typeJ == H)
  {
    char ctr;
    std::cin >> ctr;
    switch(ctr)
    {
    case '1':
      npos = Vector(v.x-1,v.y+1);
      break;
    case '2':
      npos = Vector(v.x,v.y+1);
      break;
    case '3':
      npos = Vector(v.x+1,v.y+1);
      break;
    case '4':
      npos = Vector(v.x-1,v.y);
      break;
    case '5':
      npos = Vector(v.x,v.y);
      break;
    case '6':
      npos = Vector(v.x+1,v.y);
      break;
    case '7':
      npos = Vector(v.x-1,v.y-1);
      break;
    case '8':
      npos = Vector(v.x,v.y-1);
      break;
    case '9':
      npos = Vector(v.x+1,v.y-1);
      break;
    }
  }
  else if (typeJ == IA)
  {
    npos = Vector(v.x,v.y);
  }
  
  pos = npos;
}
void PlayerController::ResetPos()
{
  pos.x = 0;
  pos.y = 0;
}
void PlayerController::PPoints(int p)
{
  points += p;
}
void PlayerController::PCoup()
{
  nbcoup++;
}
int PlayerController::GetPCoup()
{
  return nbcoup;
}
PlayerController::TypeJ PlayerController::GetTypeJ()
{
  return typeJ;
}
char PlayerController::iaJouer(Terrain *&T,Vector &v)
{
  char res;
  float d=1000.;
  Vector u = pos;
  int porter = T->getNode(Vector(u.x,u.y))->getPorter();
  for (int i=1;i<10;i++){
    u = pos;
    switch(i)
  {
  case 8:
    if(T->getNode(Vector(u.x,u.y-porter)) != NULL)
    {
      u.y -= porter;
      if (d > u.distance(v)){
        d = u.distance(v);
        res = '8';
      }
    }
    break;
  case 2:
    if(T->getNode(Vector(u.x,u.y+porter)) != NULL)
    {
      u.y += porter;
      if (d > u.distance(v)){
        d = u.distance(v);
        res = '2';
      }
    }
    break;
  case 6:
    if(T->getNode(Vector(u.x+porter,u.y)) != NULL)
    {
      u.x += porter;
      if (d > u.distance(v)){
        d = u.distance(v);
        res = '6';
      }
    }
    break;
  case 4:
    if(T->getNode(Vector(u.x-porter,u.y)) != NULL)
    {
      u.x -= porter;
      if (d > u.distance(v)){
        d = u.distance(v);
        res = '4';
      }
    }
    break;
  case 7:
    if(T->getNode(Vector(u.x-porter,u.y-porter)) != NULL)
    {
      u.x -= porter;
      u.y -= porter;
      if (d > u.distance(v)){
        d = u.distance(v);
        res = '7';
      }
    }
    break;
  case 9:
    if(T->getNode(Vector(u.x+porter,u.y-porter)) != NULL)
    {
      u.x += porter;
      u.y -= porter;
      if (d > u.distance(v)){
        d = u.distance(v);
        res = '9';
      }
    }
    break;
  case 1:
    if(T->getNode(Vector(u.x-porter,u.y+porter)) != NULL)
    {
      u.x -= porter;
      u.y += porter;
      if (d > u.distance(v)){
        d = u.distance(v);
        res = '1';
      }
    }
    break;
    case 3:
      if(T->getNode(Vector(u.x+porter,u.y+porter)) != NULL)
      {
        u.x += porter;
        u.y += porter;
      if (d > u.distance(v)){
        d = u.distance(v);
        res = '3';
      }
      }      
      break;
  }
  }
  return res;
}
