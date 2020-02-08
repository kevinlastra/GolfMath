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
