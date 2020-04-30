#ifndef NOEUDA_
#define NOEUDA_

#include "Node.h"
#include "Terrain.h"

class NoeudA
{	
	public :
	Node* node;
	int cout;
	int heuristique;
	NoeudA* pere;

	NoeudA(Node*, int, int, NoeudA*);
	NoeudA();
	void operator=(NoeudA);
};
void remonter(NoeudA);
Node* cheminPlusCourt(Terrain*,Node*,Node*);

#endif