#include "PlayerController.h"
#include <iostream>

PlayerController::PlayerController():nbcoup(0)
{
  pos = Vector(0,0);
}
PlayerController::PlayerController(Vector &v):nbcoup(0)
{
  pos = v;
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
  char ctr;
  std::cin >> ctr;
  Vector npos;
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
