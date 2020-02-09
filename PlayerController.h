#include <string>
#include "Vector.h"
class PlayerController
{
 private:
  Vector pos;
  int nbcoup;
  int points;
 public:
  PlayerController();
  PlayerController(Vector&);
  Vector& GetPos();
  void SetPos(Vector&);
  void SetPosAtTerrain(Vector&);
  void ResetPos();

  void PPoints(int);
  void PCoup();
  int GetPCoup();
};
