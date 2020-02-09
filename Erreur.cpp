#include "Erreur.h"
#include <iostream>
#include <string.h>

char Erreur::str[100] = {0};
Erreur::Erreur(EType et)
{
  switch(et)
  {
  case MOVEMENT:
    strcpy(str,"Movement impossible");
    break;
  case ARGUMENT:
    strcpy(str,"Erreur d'argument");
    break;
  case NONE:
    strcpy(str,"");
    break;
  default:
    strcpy(str,"default erreur");
    break;
  }
}
void Erreur::print()
{
  if(Erreur::str[0])
    std::cout << Erreur::str << std::endl;
  strcpy(str,"");
}
