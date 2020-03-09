#include "LevelsManager.h"
#include <string>
#include <iostream>
#include <fstream>

LevelsManager::LevelsManager()
{
  file = std::ifstream("levels.txt");
}
void LevelsManager::SetHeadDoc(int i)
{
  std::string s;
  getline(file,s);
  while(true)
  {
    if(atoi(s.c_str())-48 != i)
      {
	getline(file, s);
	std::cout << s << std::endl;
	int h = 0;
	int pos = 0;
	int last = 0;
	while(h < 5)
	  {
	    int last = pos;
	    int pos = s.find_first_of("_");
	    s.substr(pos+1,s.size()-(pos+1));
	    std::cout << "=>>>"<<last <<"   "<<pos<<"   "<<s << std::endl;
	    h++;
	  }
	break;
	int newp = atoi(s.substr(last,last+2).c_str())-48;
	std::cout << newp << std::endl;
	std::cout << s.substr(last,pos-last+1).c_str() << std::endl;
	std::cout << last << std::endl;
	std::cout << pos << std::endl;
	while(newp > 0)
	  {
	    getline(file,s);
	  }
      }
    else
      break;
  }
  std::cout << s << std::endl;
}

int main()
{
  LevelsManager l;
  l.SetHeadDoc(0);
  
  return 1;
}
