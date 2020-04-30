#include <queue>
#include "NoeudA.h"
#include "Terrain.h"
#include "Node.h"
#include "Vector.h"
#include <iostream>
using namespace std;

NoeudA::NoeudA(Node* n, int c, int h, NoeudA* p){
	node = n;
	cout = c;
	heuristique = h;
	pere = p;
}	

NoeudA::NoeudA(){
	Node* n;
	node = n;
	cout=0;
	heuristique=0;
	pere=NULL;
}

void NoeudA::operator=(NoeudA n){
	node = n.node;
	cout = n.cout;
	heuristique = n.heuristique;
	pere = n.pere;
}

struct Compare { 
    bool operator()(NoeudA n1, NoeudA n2) 
    { 
        return n1.heuristique > n2.heuristique; 
    } 
}; 

bool appartientOpen(NoeudA noeud, priority_queue<NoeudA, vector<NoeudA>,Compare> list){
	bool b=false;
	while (!list.empty() && !b){
		NoeudA u=list.top();
		if(noeud.node->getPos() == u.node->getPos() && noeud.cout > u.cout){
			b=true;
		}
		list.pop();
	}
	return b;
}

bool appartienClosed(NoeudA noeud, queue<NoeudA> list){
	bool b=false;
	while (!list.empty() && !b){
		NoeudA u=list.front();
		if(noeud.node->getPos() == u.node->getPos()){
			b=true;
		}
		list.pop();
	}
    return b;
}

Node* cheminPlusCourt(Terrain* T,Node* d,Node* o){
    queue<NoeudA> closedList;
	priority_queue<NoeudA, vector<NoeudA>, Compare> openList;
	Vector oPos = o->getPos();
	NoeudA depart = NoeudA(d,0,d->getPos().distance(oPos),NULL);
	NoeudA objectif(o,0,0,NULL);
	openList.push(depart);
	NoeudA last = NoeudA();
	bool stop = false;
	NoeudA stock[1000];
	Node chemin[100] = {Node()};
	for(int i=0;i<100;i++){

	}
	int index=0;
	int indexChemin=0;
	Node* vrai = new Node[100];
	while (!openList.empty() && !stop)
	{	
		stock[index] = openList.top();
		openList.pop();
		if (stock[index].node->getPos() == objectif.node->getPos()){
			last = stock[index];
			stop = true;
			break;
		}
		for (int i=1;i<=9;i++)
		{
			if (i != 5){
			NoeudA v = NoeudA();
			int porter = T->getNode(Vector(stock[index].node->getPos().x,stock[index].node->getPos().y))->getPorter();
			switch(i)
		  {
		  case 8:
		    if(T->getNode(Vector(stock[index].node->getPos().x,stock[index].node->getPos().y-porter)) != NULL){
		      v.node = T->getNode(Vector(stock[index].node->getPos().x,stock[index].node->getPos().y-porter));
		  	  v.cout = stock[index].cout+1;
		  	  v.heuristique =v.cout + v.node->getPos().distance(oPos);
		  	  v.pere = &stock[index];}
		    if (T->getNode(Vector(stock[index].node->getPos().x,stock[index].node->getPos().y-porter)) != NULL && T->getNode(Vector(stock[index].node->getPos().x,stock[index].node->getPos().y-porter))->getType() != Node::NONE  
		    	&& !appartienClosed(v,closedList) && !appartientOpen(v,openList))
		    {
		      
		      openList.push(v);
		    }
		    break;
		  case 2:
		    if(T->getNode(Vector(stock[index].node->getPos().x,stock[index].node->getPos().y+porter)) != NULL){
		      v.node = T->getNode(Vector(stock[index].node->getPos().x,stock[index].node->getPos().y+porter));
		  	  v.cout = stock[index].cout+1;
		  	  v.heuristique =v.cout + v.node->getPos().distance(oPos);
		  	  v.pere = &stock[index];}
		    if(T->getNode(Vector(stock[index].node->getPos().x,stock[index].node->getPos().y+porter)) != NULL && T->getNode(Vector(stock[index].node->getPos().x,stock[index].node->getPos().y+porter))->getType() != Node::NONE  
		    	&& !appartienClosed(v,closedList) 
		    	&& !appartientOpen(v,openList))
		    {
		      
		      openList.push(v);
		    }
		    break;
		  case 6:
		    if(T->getNode(Vector(stock[index].node->getPos().x+porter,stock[index].node->getPos().y)) != NULL){
		  	  v.node = T->getNode(Vector(stock[index].node->getPos().x+porter,stock[index].node->getPos().y));
		  	  v.cout = stock[index].cout+1;
		  	  v.heuristique =v.cout + v.node->getPos().distance(oPos);
		  	  v.pere = &stock[index];}
		    if(T->getNode(Vector(stock[index].node->getPos().x+porter,stock[index].node->getPos().y)) != NULL && T->getNode(Vector(stock[index].node->getPos().x+porter,stock[index].node->getPos().y))->getType() != Node::NONE  
		    	&& !appartienClosed(v,closedList) 
		    	&& !appartientOpen(v,openList))
		    {
		      
		      openList.push(v);
		    }
		    break;
		  case 4:
		    if(T->getNode(Vector(stock[index].node->getPos().x-porter,stock[index].node->getPos().y)) != NULL){
		  	  v.node = T->getNode(Vector(stock[index].node->getPos().x-porter,stock[index].node->getPos().y));
		  	  v.cout = stock[index].cout+1;
		  	  v.heuristique =v.cout + v.node->getPos().distance(oPos);
		  	  v.pere = &stock[index];}
		    if(T->getNode(Vector(stock[index].node->getPos().x-porter,stock[index].node->getPos().y)) != NULL && T->getNode(Vector(stock[index].node->getPos().x-porter,stock[index].node->getPos().y))->getType() != Node::NONE  
		    	&& !appartienClosed(v,closedList) 
		    	&& !appartientOpen(v,openList))
		    {
		      
		      openList.push(v);
		    }
		    break;
		  case 7:
		    if(T->getNode(Vector(stock[index].node->getPos().x-porter,stock[index].node->getPos().y-porter)) != NULL){
		  	  v.node = T->getNode(Vector(stock[index].node->getPos().x-porter,stock[index].node->getPos().y-porter));
		  	  v.cout = stock[index].cout+1;
		  	  v.heuristique =v.cout + v.node->getPos().distance(oPos);
		  	  v.pere = &stock[index];}
		    if(T->getNode(Vector(stock[index].node->getPos().x-porter,stock[index].node->getPos().y-porter)) != NULL && T->getNode(Vector(stock[index].node->getPos().x-porter,stock[index].node->getPos().y-porter))->getType() != Node::NONE  
		    	&& !appartienClosed(v,closedList) 
		    	&& !appartientOpen(v,openList))
		    {
		      
		      openList.push(v);
		    }
		    break;
		  case 9:
		    if(T->getNode(Vector(stock[index].node->getPos().x+porter,stock[index].node->getPos().y-porter)) != NULL){
		  	  v.node = T->getNode(Vector(stock[index].node->getPos().x+porter,stock[index].node->getPos().y-porter));
		  	  v.cout = stock[index].cout+1;
		  	  v.heuristique =v.cout + v.node->getPos().distance(oPos);
		  	  v.pere = &stock[index];}
		    if(T->getNode(Vector(stock[index].node->getPos().x+porter,stock[index].node->getPos().y-porter)) != NULL && T->getNode(Vector(stock[index].node->getPos().x+porter,stock[index].node->getPos().y-porter))->getType() != Node::NONE  
		    	&& !appartienClosed(v,closedList) 
		    	&& !appartientOpen(v,openList))
		    {
		      
		      openList.push(v);
		    }
		    break;
		  case 1:
		    if(T->getNode(Vector(stock[index].node->getPos().x-porter,stock[index].node->getPos().y+porter)) != NULL){
		  	  v.node = T->getNode(Vector(stock[index].node->getPos().x-porter,stock[index].node->getPos().y+porter));
		  	  v.cout = stock[index].cout+1;
		  	  v.heuristique =v.cout + v.node->getPos().distance(oPos);
		  	  v.pere = &stock[index];}
		    if(T->getNode(Vector(stock[index].node->getPos().x-porter,stock[index].node->getPos().y+porter)) != NULL && T->getNode(Vector(stock[index].node->getPos().x-porter,stock[index].node->getPos().y+porter))->getType() != Node::NONE  
		    	&& !appartienClosed(v,closedList) 
		    	&& !appartientOpen(v,openList))
		    {
		      
		      openList.push(v);
		    }
		    break;
		    case 3:
		    if(T->getNode(Vector(stock[index].node->getPos().x+porter,stock[index].node->getPos().y+porter)) != NULL){
		  	  v.node = T->getNode(Vector(stock[index].node->getPos().x+porter,stock[index].node->getPos().y+porter));
		  	  v.cout = stock[index].cout+1;
		  	  v.heuristique =v.cout + v.node->getPos().distance(oPos);
		  	  v.pere = &stock[index];}
		      if(T->getNode(Vector(stock[index].node->getPos().x+porter,stock[index].node->getPos().y+porter)) != NULL && T->getNode(Vector(stock[index].node->getPos().x+porter,stock[index].node->getPos().y+porter))->getType() != Node::NONE  
		    	&& !appartienClosed(v,closedList) 
		    	&& !appartientOpen(v,openList))
		      {
		      
		      openList.push(v);
		      }      
		      break;
		  }		  
		}
		}
		closedList.push(stock[index]);
		index++;
	}
	while (last.pere != NULL){
		chemin[indexChemin]=*last.node;
		last.node=last.pere->node;
		last.cout=last.pere->cout;
		last.heuristique=last.pere->heuristique;
		last.pere=last.pere->pere;
		indexChemin++;
	}
	int k = indexChemin-1;
	for(int i=0;i<indexChemin;i++){
		vrai[i]=chemin[k];
		k--;
	}
    int oui = 0;
	return vrai;
}

void remonter(NoeudA n){
	while (n.pere != NULL){
		n.node=n.pere->node;
		n.cout=n.pere->cout;
		n.heuristique=n.pere->heuristique;
		n.pere=n.pere->pere;
		//n=*n.pere;
	}
	//cout<<"("<<n.node->getPos().x<<","<<n.node->getPos().y<<")"<<endl;
	//cout<<"("<<n.pere->node->getPos().x<<","<<n.pere->node->getPos().y<<")"<<endl;
}
