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
  case NONE:
    strcpy(str,"");
    break;
  }
}
void Erreur::print()
{
  if(Erreur::str[0])
    std::cout << Erreur::str << std::endl;
  strcpy(str,"");
}
