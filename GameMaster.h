#include "Terrain.h"
#include "PlayerController.h"
#include <string>
class GameMaster
{
 private:
  Terrain *T;
  PlayerController Players[4];
  int nbplayers = 0;

  std::string entete;
  
 public:
  GameMaster();
  void GenerateTerrain(std::string&);
  void AddPlayer();
  void PrintMap();
  void Start();
  
  void Interactuer();
  void RequeteMovement(int);
  
  void RequeteNBJouers();
  
  bool playerAtPos(Vector&);
  int getNbPlayers();
};