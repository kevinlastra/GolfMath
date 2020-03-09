#ifndef LEVELMANAGER
#define LEVELMANAGER

#include <iostream>
#include <fstream>
#include <string.h>

class LevelsManager
{
 public:
  std::ifstream file;
  
  LevelsManager();
  void SetHeadDoc(int);
};

#endif
