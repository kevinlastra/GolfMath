#include <iostream>
#include <stdlib.h>
#include <cmath>

#define x_ 40
#define y_ 40
#define nbMove 10
#define marge 5

float X[x_][y_];
int SX[nbMove];
int SY[nbMove];
int seed;
int trynumber = 0;
typedef struct
{
  int x;
  int y;
}vecteur;

bool inRadius(int,int);
float dist(float a, float b)
{
  return sqrt(a*a+b*b);
}
vecteur findextrem(int ex, int ey)
{
  vecteur v;
  float maxdist = 0;
  for(int x = 0; x < x_; x++)
  {
    for(int y = 0;y < y_;y++)
    {
      float d = dist(x-ex,y-ey);
      if(d > maxdist && inRadius(x,y))
      {
	maxdist = d;
	v.x = x;
	v.y = y;
      }
    }
  }
  return v;
}
int GetPortee(int x,int y,int ex,int ey,vecteur extrem)
{
  float dist_ = dist(ex-x,ey-y);
  
  float space = dist(SX[0]-extrem.x,SY[0]-extrem.y)+1;
  
  int portee = (2+(int)((dist_*8)/space)%8) + ((rand()%5)-2)%2;
  if(portee > 9)
    return 9;
  else if(portee < 1)
    return 1;
  else
    return portee;
}
bool inRadius(int x, int y)
{
  for(int i = 1; i < nbMove-1;i++)
  {
    int max;
    if(SX[i] == SX[i+1])
      max = abs(SY[i] - SY[i+1]);
    else
      max = abs(SX[i] - SX[i+1]);
    if(dist(x-SX[i],y-SY[i]) < max)
    {
      return true;
    }
  }
  if(dist(x-SX[nbMove-1],y-SY[nbMove-1]) < 9 || dist(x-SX[0],y-SY[0]) < 9)
  {
    return true;
  }
  return false;
}

int main()
{
  seed = time(NULL);
  srand(seed);
  bool truedraw = true;

  while(truedraw)
  {
    trynumber++;
    int compt = 15;


    //init
    for(int x = 0; x < x_;x++)
    {
      for(int y = 0; y < y_;y++)
      {
	X[x][y] = 0;
      }
    }

    
    int i = nbMove-1;
    //start point
    int tx = rand()%(x_/2);
    int ty = rand()%(x_/2);
    //last
    int lastdir = 10;
    float lastdist = 0;
    int lastI = 9;
    SX[i] = tx;
    SY[i] = ty;
    i--;
    while(i >= 0)
    {
      if(i == lastI)
	compt--;
      if(compt == 0)
	break;
      lastI = i;
      int direction = rand()%8;
      int dist_ = rand()%10;
      int px = SX[i+1];
      int py = SY[i+1];
      
      if((9-direction) == lastdir)
	  continue;
      switch(direction)
      {
      case 1:
	px -= dist_;
	py += dist_;
	break;
      case 2:
	py += dist_;
	break;
      case 3:
	px += dist_;
	py += dist_;
	break;
      case 4:
	px -= dist_;
	break;
      case 5:
	px += dist_;
	break;
      case 6:
	px -= dist_;
	py -= dist_;
	break;
      case 7:
	py -= dist_;
	break;
      case 8:
	px += dist_;
	py -= dist_;
	break;
      default:
	continue;
      }
      if(px > marge && px < x_-marge && py > marge && py < y_-marge && X[px][py] == 0 && dist(px-tx,py-ty) > lastdist)
      {
	X[SX[i+1]][SY[i+1]] = dist_;
	SX[i] = px;
	SY[i] = py;
	i--;
	lastdist = dist(px-tx,py-ty);
	lastdir = direction;
	if(i == -1)
	  truedraw = false;
      }
    }
  }
  int i = 0;

  X[SX[0]-1][SY[0]-1] = 1;
  X[SX[0]][SY[0]-1] = 1;
  X[SX[0]+1][SY[0]-1] = 1;
  X[SX[0]-1][SY[0]] = 1;
  X[SX[0]+1][SY[0]] = 1;
  X[SX[0]-1][SY[0]+1] = 1;
  X[SX[0]][SY[0]+1] = 1;
  X[SX[0]+1][SY[0]+1] = 1;
  vecteur ext = findextrem(SX[0],SY[0]);
  for(int x = 0; x < x_;x++)
  {
    for(int y = 0; y < y_;y++)
    {
      if(X[x][y] > 0)
	std::cout << " \033[1;31m"<<X[x][y]<<"\033[0m";
      else if(X[x][y] == 0 && inRadius(x,y))
	std::cout << " "<<GetPortee(x,y,SX[0],SY[0],ext);
      else
	std::cout <<" _" ;
    }
    std::cout << std::endl;
  }
  std::cout << "set after "<<trynumber<<" try"<<std::endl;
  std::cout << "seed: "<<seed<<std::endl;
  return 1;
}