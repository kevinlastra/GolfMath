#include <queue>
#include "NoeudA.h"
#include "Terrain.h"
#include "Node.h"
#include "Vector.h"
#include <iostream>
using namespace std;

NoeudA::NoeudA(Node* n, int c, int h, NoeudA* p){
	node= *n;
	cout=c;
	heuristique=h;
	pere=p;
}	

NoeudA::NoeudA(){
	node = Node();
	cout=0;
	heuristique=0;
	pere=NULL;
}

struct Compare { 
    bool operator()(NoeudA n1, NoeudA n2) 
    { 
        return n1.heuristique < n2.heuristique; 
    } 
}; 

bool appartientOpen(NoeudA noeud, priority_queue<NoeudA, vector<NoeudA>,Compare> list){
	bool b=false;
	while (!list.empty() && !b){
		NoeudA u=list.top();
		if(noeud.node.getPos() == u.node.getPos() && noeud.cout > u.cout){
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
		if(noeud.node.getPos() == u.node.getPos()){
			b=true;
		}
		list.pop();
	}
}

NoeudA cheminPlusCourt(Terrain* T,Node* d,Node* o){
	queue<NoeudA> closedList;
	priority_queue<NoeudA, vector<NoeudA>, Compare> openList;
	Vector oPos = o->getPos();
	NoeudA depart = NoeudA(d,0,d->getPos().distance(oPos),NULL);
	NoeudA objectif(o,0,0,NULL);
	openList.push(depart);
	NoeudA last = NoeudA();
	bool stop = false;
	cout<<"("<<d->getPos().x<<" "<<d->getPos().y<<")"<<endl;
	cout<<"("<<o->getPos().x<<" "<<o->getPos().y<<")"<<endl;
	while (!openList.empty() && !stop)
	{	
		cout<<"oui"<<endl;
		NoeudA u = openList.top();
		openList.pop();
		if (u.node.getPos() == objectif.node.getPos()){
			cout<<"("<<u.node.getPos().x<<" "<<u.node.getPos().y<<")"<<endl;
			cout<<"("<<objectif.node.getPos().x<<" "<<objectif.node.getPos().y<<")"<<endl;
			cout<<"ouiIF"<<endl;
			last = u;
			stop = true;
			break;
		}
		for (int i=1;i<=9;i++)
		{
			NoeudA v = NoeudA();
			int porter = T->getNode(Vector(u.node.getPos().x,u.node.getPos().y))->getPorter();
			cout<<"ouiFor"<<endl;
			switch(i)
		  {
		  case 8:
		  	v = NoeudA(T->getNode(Vector(u.node.getPos().x,u.node.getPos().y-porter)),u.cout+1,v.cout + v.node.getPos().distance(oPos),&u);
		    if(T->getNode(Vector(u.node.getPos().x,u.node.getPos().y-porter)) != NULL && T->getNode(Vector(u.node.getPos().x,u.node.getPos().y-porter))->getType() != Node::eau  
		    	&& !appartienClosed(v,closedList) && !appartientOpen(v,openList))
		    {	
		      openList.push(v);
		    }
		    break;
		  case 2:
		 	v = NoeudA(T->getNode(Vector(u.node.getPos().x,u.node.getPos().y+porter)),u.cout+1,v.cout + v.node.getPos().distance(oPos),&u);
		    if(T->getNode(Vector(u.node.getPos().x,u.node.getPos().y+porter)) != NULL && T->getNode(Vector(u.node.getPos().x,u.node.getPos().y+porter))->getType() != Node::eau  
		    	&& !appartienClosed(v,closedList) 
		    	&& !appartientOpen(v,openList))
		    {
		      openList.push(v);
		    }
		    break;
		  case 6:
		  	v = NoeudA(T->getNode(Vector(u.node.getPos().x+porter,u.node.getPos().y)),u.cout+1,v.cout + v.node.getPos().distance(oPos),&u);
		    if(T->getNode(Vector(u.node.getPos().x+porter,u.node.getPos().y)) != NULL && T->getNode(Vector(u.node.getPos().x+porter,u.node.getPos().y))->getType() != Node::eau  
		    	&& !appartienClosed(v,closedList) 
		    	&& !appartientOpen(v,openList))
		    {
		      openList.push(v);
		    }
		    break;
		  case 4:
		  	v = NoeudA(T->getNode(Vector(u.node.getPos().x-porter,u.node.getPos().y)),u.cout+1,v.cout + v.node.getPos().distance(oPos),&u);
		    if(T->getNode(Vector(u.node.getPos().x-porter,u.node.getPos().y)) != NULL && T->getNode(Vector(u.node.getPos().x-porter,u.node.getPos().y))->getType() != Node::eau  
		    	&& !appartienClosed(v,closedList) 
		    	&& !appartientOpen(v,openList))
		    {
		      openList.push(v);
		    }
		    break;
		  case 7:
		  	v = NoeudA(T->getNode(Vector(u.node.getPos().x-porter,u.node.getPos().y-porter)),u.cout+1,v.cout + v.node.getPos().distance(oPos),&u);
		    if(T->getNode(Vector(u.node.getPos().x-porter,u.node.getPos().y-porter)) != NULL && T->getNode(Vector(u.node.getPos().x-porter,u.node.getPos().y-porter))->getType() != Node::eau  
		    	&& !appartienClosed(v,closedList) 
		    	&& !appartientOpen(v,openList))
		    {
		      openList.push(v);
		    }
		    break;
		  case 9:
		  	v = NoeudA(T->getNode(Vector(u.node.getPos().x+porter,u.node.getPos().y-porter)),u.cout+1,v.cout + v.node.getPos().distance(oPos),&u);
		    if(T->getNode(Vector(u.node.getPos().x+porter,u.node.getPos().y-porter)) != NULL && T->getNode(Vector(u.node.getPos().x+porter,u.node.getPos().y-porter))->getType() != Node::eau  
		    	&& !appartienClosed(v,closedList) 
		    	&& !appartientOpen(v,openList))
		    {
		      openList.push(v);
		    }
		    break;
		  case 1:
		  	v = NoeudA(T->getNode(Vector(u.node.getPos().x-porter,u.node.getPos().y+porter)),u.cout+1,v.cout + v.node.getPos().distance(oPos),&u);
		    if(T->getNode(Vector(u.node.getPos().x-porter,u.node.getPos().y+porter)) != NULL && T->getNode(Vector(u.node.getPos().x-porter,u.node.getPos().y+porter))->getType() != Node::eau  
		    	&& !appartienClosed(v,closedList) 
		    	&& !appartientOpen(v,openList))
		    {
		      openList.push(v);
		    }
		    break;
		    case 3:
		  	v = NoeudA(T->getNode(Vector(u.node.getPos().x+porter,u.node.getPos().y+porter)),u.cout+1,v.cout + v.node.getPos().distance(oPos),&u);
		      if(T->getNode(Vector(u.node.getPos().x+porter,u.node.getPos().y+porter)) != NULL && T->getNode(Vector(u.node.getPos().x+porter,u.node.getPos().y+porter))->getType() != Node::eau  
		    	&& !appartienClosed(v,closedList) 
		    	&& !appartientOpen(v,openList))
		      {
		      openList.push(v);
		      }      
		      break;
		  }
		  closedList.push(u);
		}
		
	}
	return last;
}

void remonter(NoeudA n){
	while (n.pere->pere != NULL){
		cout<<"("<<n.node.getPos().x<<","<<n.node.getPos().y<<")"<<endl;
		n.node=n.pere->node;
		n.cout=n.pere->cout;
		n.heuristique=n.pere->heuristique;
		n.pere=n.pere->pere;
	}
	cout<<"("<<n.node.getPos().x<<","<<n.node.getPos().y<<")"<<endl;
}