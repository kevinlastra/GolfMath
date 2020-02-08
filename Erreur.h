#ifndef ERREUR_H
#define ERREUR_H

#include <string>
class Erreur
{
 public:
  enum EType{MOVEMENT,NONE};
  static char str[100];
 private:
  EType type;
 public:
  Erreur(EType);
  static void print();
};

#endif

