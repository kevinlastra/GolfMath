#include <string>
#include "Vector.h"
#include "Terrain.h"
class PlayerController
{
 public :
 enum TypeJ {NONE=0, H, IA};
 private:
  Vector pos;
  int nbcoup;
  int points;
  TypeJ typeJ;
 public:
  PlayerController();
  PlayerController(TypeJ t);
  PlayerController(Vector&,TypeJ);
  Vector& GetPos();
  TypeJ GetTypeJ();
  void SetPos(Vector&);
  void SetPosAtTerrain(Vector&);
  void ResetPos();
  char iaJouer(Terrain*&,Vector&);

  void PPoints(int);
  void PCoup();
  int GetPCoup();
};
