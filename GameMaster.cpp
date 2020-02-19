#include "GameMaster.h"
#include "Vector.h"
#include <string>
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include "Erreur.h"

GameMaster::GameMaster(){}
void GameMaster::GenerateTerrain(std::string &s)
{
  T = new Terrain(s);
}
void GameMaster::AddPlayer()
{
  PrintMap();
  std::cout << "start position?"<<std::endl;
  PlayerController p;
  p.SetPosAtTerrain(T->getStartPos());
  Players[nbplayers] = p;
  nbplayers++;
}
void GameMaster::PrintMap()
{
  std::cout <<"\033[2J";
  Erreur::print();
  for(int j = 0; j < T->getLar();j++)
  {
    for(int i = 0; i < T->getLon();i++)
    {
      Vector v(i,j);
      if(playerAtPos(v))
      {
	std::cout << "\033[1;42m\033[1;35m[P]\033[0m";
      }
      else
      {
	switch(T->getNode(v)->getType())
	{
        case Node::herbe:
	  std::cout << "\033[1;42m\033[1;32m["<<T->getNode(v)->getPorter()<<"]\033[0m";
	  break;
        case Node::start:
	  std::cout << "\033[1;43m\033[1;33m["<<T->getNode(v)->getPorter()<<"]\033[0m";
	  break;
	case Node::end:
	  std::cout << "\033[1;42m\033[1;34m[T]\033[0m";
	  break;
	case Node::sable:
	  std::cout << "\033[1;43m\033[1;33m["<<T->getNode(v)->getPorter()<<"]\033[0m";
	  break;
	default:
	  std::cout << "\033[1;44m\033[1;34m  ~\033[0m";
	  break;
	}
      }
    }
    std::cout << std::endl;
  }
}
void GameMaster::Start()
{
  std::string mapPath = "testmap.txt";
  GenerateTerrain(mapPath);
  RequeteNBJouers();
  Interactuer();
}
void GameMaster::Interactuer()
{
  bool stop = false;
  int nbcoup = 0;
  int Player = 0;
  while(!stop)
  {
    PrintMap();
    RequeteMovement(Player);
    
    if(Players[Player].GetPos() == T->getTargetPos())
    {
      PrintMap();
      std::cout << "YOU WIN           nbcoup:"<<Players[Player].GetPCoup() << std::endl;
      stop = true;
    }
    
    Player++;
    if(Player == nbplayers)
      Player = 0;
  }
}
void GameMaster::RequeteMovement(int i)
{
  char ctr;
  std::cin >> ctr;
  Vector npos(Players[i].GetPos());
  int porter = T->getNode(Vector(npos.x,npos.y))->getPorter();
  switch(ctr)
  {
  case '8':
    if(T->getNode(Vector(npos.x,npos.y-porter)) != NULL)
    {
      npos.y -= porter;
    }
    else
      Erreur(Erreur::MOVEMENT);
    break;
  case '2':
    if(T->getNode(Vector(npos.x,npos.y+porter)) != NULL)
    {
      npos.y += porter;
    }
    else
      Erreur(Erreur::MOVEMENT);
    break;
  case '6':
    if(T->getNode(Vector(npos.x+porter,npos.y)) != NULL)
    {
      npos.x += porter;
    }
    else
      Erreur(Erreur::MOVEMENT);
    break;
  case '4':
    if(T->getNode(Vector(npos.x-porter,npos.y)) != NULL)
    {
      npos.x -= porter;
    }
    else
      Erreur(Erreur::MOVEMENT);
    break;
  case '7':
    if(T->getNode(Vector(npos.x-porter,npos.y-porter)) != NULL)
    {
      npos.x -= porter;
      npos.y -= porter;
    }
    else
      Erreur(Erreur::MOVEMENT);
    break;
  case '9':
    if(T->getNode(Vector(npos.x+porter,npos.y-porter)) != NULL)
    {
      npos.x += porter;
      npos.y -= porter;
    }
    else
      Erreur(Erreur::MOVEMENT);
    break;
  case '1':
    if(T->getNode(Vector(npos.x-porter,npos.y+porter)) != NULL)
    {
      npos.x -= porter;
      npos.y += porter;
    }
    else
      Erreur(Erreur::MOVEMENT);
    break;
    case '3':
      if(T->getNode(Vector(npos.x+porter,npos.y+porter)) != NULL)
      {
	npos.x += porter;
	npos.y += porter;
      }
      else
	Erreur(Erreur::MOVEMENT);
      break;
  }
  Players[i].SetPos(npos);
  Players[i].PCoup();
}
void GameMaster::RequeteNBJouers()
{
  int n = -1;
  while(true)
  {
    std::cout << "combien de jouers[0-4]?" << std::endl;
    std::cin >> n;
    if(n >= 0 && n <= 4)
      break;
    Erreur(Erreur::ARGUMENT);
    Erreur::print();
  }

  for(int i = 0;i < n;i++)
  {
    AddPlayer();
  }
}

bool GameMaster::playerAtPos(Vector &v)
{
  for(int i = 0;i < nbplayers;i++)
  {
    if(Players[i].GetPos() == v)
    {
      return true;
    } 
  }
  return false;
}
int GameMaster::getNbPlayers(){return nbplayers;}
