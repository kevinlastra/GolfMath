#ifndef NOEUDA_
#define NOEUDA_

#include "Node.h"
#include "Terrain.h"

struct NoeudA
{
	Node node;
	int cout;
	int heuristique;
	NoeudA* pere;

	NoeudA(Node*, int, int, NoeudA*);
	NoeudA();
};
void remonter(NoeudA);
NoeudA cheminPlusCourt(Terrain*,Node*,Node*);

#endif