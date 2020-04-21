#include "Terrain.h"
#include "PlayerController.h"
#include <string>
#include "NoeudA.h"
class GameMaster
{
 private:
  Terrain *T;
  PlayerController Players[5];
  int nbplayers = 0;
  int nbniveaux = 1;
  std::string entete;
  
 public:
  GameMaster();
  void GenerateTerrain(std::string&);
  void GenerateTerrain(Vector,int,int,int);
  void AddPlayer(PlayerController::TypeJ t);
  void PrintMap();
  void Start();
  
  void Interactuer();
  void RequeteMovement(int,int);
  
  void RequeteNBJouers();
  
  bool playerAtPos(Vector&);
  int getNbPlayers();
};
