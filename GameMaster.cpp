#include "GameMaster.h"
#include "Vector.h"
#include <string>
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include "Erreur.h"
#include "NoeudA.h"
//#include "NoeudA2.h"

GameMaster::GameMaster(){}
void GameMaster::GenerateTerrain(std::string &s)
{
  T = new Terrain(s);
}
void GameMaster::GenerateTerrain(Vector dim,int nbMove,int marge,int seed)
{
  T = new Terrain(seed,dim,nbMove,marge);
}
void GameMaster::AddPlayer(PlayerController::TypeJ t)
{
  PrintMap();
  if(t==PlayerController::H){std::cout << "start position?"<<std::endl;}
  PlayerController p = PlayerController(t);
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
  std::cout << "auto gen. map(0) or default map(1)?"<<std::endl;
  int i;
  std::cin >>i;
  if( i == 1)
  {
    std::string mapPath = "testmap.txt";
    GenerateTerrain(mapPath);
  }
  else
    GenerateTerrain(Vector(40,40),10,5,-1);
  RequeteNBJouers();
  /*std::cout<<"("<<T->getStartPos().x<<" "<<T->getStartPos().y<<")"<<std::endl;
  std::cout<<"("<<T->getNode(T->getStartPos())->getPos().x<<" "<<T->getNode(T->getStartPos())->getPos().y<<")"<<std::endl;
  std::cout<<"("<<T->getTargetPos().x<<" "<<T->getTargetPos().y<<")"<<std::endl;
  std::cout<<"("<<T->getNode(T->getTargetPos())->getPos().x<<" "<<T->getNode(T->getTargetPos())->getPos().y<<")"<<std::endl;
  std::cout<<(T->getNode(T->getStartPos())->getPos().x == T->getStartPos().x)<<std::endl;*/
  NoeudA noeud = cheminPlusCourt(T,T->getNode(T->getStartPos()),T->getNode(T->getTargetPos()));
  //remonter(noeud);
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
  if (Players[i].GetTypeJ()==PlayerController::H)
  {
  std::cin >> ctr;
  }
  else if (Players[i].GetTypeJ()==PlayerController::IA)
  {
    ctr = Players[i].iaJouer(T,T->getTargetPos());
  }
  Vector npos(Players[i].GetPos());
  int porter = T->getNode(Vector(npos.x,npos.y))->getPorter();
  Node* node;
  switch(ctr)
  {
  case '8':
    node = T->getNode(Vector(npos.x,npos.y-porter));
    if(node != NULL && node->getType() != Node::eau && node->getType() != Node::NONE)
    {
      npos.y -= porter;
    }
    else
      Erreur(Erreur::MOVEMENT);
    break;
  case '2':
    node = T->getNode(Vector(npos.x,npos.y+porter));
    if(node != NULL && node->getType() != Node::eau && node->getType() != Node::NONE)
    {
      npos.y += porter;
    }
    else
      Erreur(Erreur::MOVEMENT);
    break;
  case '6':
    node = T->getNode(Vector(npos.x+porter,npos.y));
    std::cout <<"type:"<< node->getType() <<std::endl;
    if(node != NULL && node->getType() != Node::eau && node->getType() != Node::NONE)
    {
      npos.x += porter;
    }
    else
      Erreur(Erreur::MOVEMENT);
    break;
  case '4':
    node = T->getNode(Vector(npos.x-porter,npos.y));
    if(node != NULL && node->getType() != Node::eau && node->getType() != Node::NONE)
    {
      npos.x -= porter;
    }
    else
      Erreur(Erreur::MOVEMENT);
    break;
  case '7':
    node = T->getNode(Vector(npos.x-porter,npos.y-porter));
    if(node != NULL && node->getType() != Node::eau && node->getType() != Node::NONE)
    {
      npos.x -= porter;
      npos.y -= porter;
    }
    else
      Erreur(Erreur::MOVEMENT);
    break;
  case '9':
    node = T->getNode(Vector(npos.x+porter,npos.y-porter));
    if(node != NULL && node->getType() != Node::eau && node->getType() != Node::NONE)
    {
      npos.x += porter;
      npos.y -= porter;
    }
    else
      Erreur(Erreur::MOVEMENT);
    break;
  case '1':
    node = T->getNode(Vector(npos.x-porter,npos.y+porter));
    if(node != NULL && node->getType() != Node::eau && node->getType() != Node::NONE)
    {
      npos.x -= porter;
      npos.y += porter;
    }
    else
      Erreur(Erreur::MOVEMENT);
    break;
  case '3':
    node = T->getNode(Vector(npos.x+porter,npos.y+porter));
    if(node != NULL && node->getType() != Node::eau && node->getType() != Node::NONE)
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
  char c;
  while(true)
  {
    std::cout << "combien de joueurs[0-4]?" << std::endl;
    std::cin >> n;
    if(n >= 0 && n <= 4)
      break;
    Erreur(Erreur::ARGUMENT);
    Erreur::print();
  }
  for(int i = 0;i < n;i++)
  {
    AddPlayer(PlayerController::H);
  }
  std::cout << "voulez-vous une IA ? \n y/n" <<std::endl ;
  std::cin >> c;
  if (c == 'y'){
    AddPlayer(PlayerController::IA);
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
