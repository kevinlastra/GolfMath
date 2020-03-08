#include "ScoreManager.h"
#include <fstream>
#include <iostream>
#include <string.h>

ScoreManager::ScoreManager()
{

  for(int i = 0; i < 10;i++)
  {
      score[i].name = "";
      score[i].points = 0;
  }

  std::ifstream file;
  file.open("score.txt");
  if(!file.is_open())
  {
    std::ofstream o("score.txt");
    o << "";
    o.close();
    file.close();
  }
  else
  {
    std::string s;
    int i = 0;
    while(getline(file,s) && !file.eof())
    {
      if(s.length() <= 1)
        continue;
      size_t l = s.find_first_of(":",0);
      score[i].name = s.substr(0,l);
      score[i].points = atoi(s.substr(l+1,s.length()).c_str());
      size = i+1;
      i++;
    }
    file.close();
  }
}
ScoreManager::Score* ScoreManager::GetScore()
{
  return score;
}
int ScoreManager::getsize()
{
  return size;  
}
bool ScoreManager::inscore(int s)
{
  if(s > score[size-1].points || size < 10)
  {
    return true;
  }
  return false;
}
void ScoreManager::sortnewscore(std::string name, int p)
{
  if(inscore(p))
  {
    if(size < 8)
      size++;
    Score s;
    s.name = name;
    s.points = p;
    int i = size;
    while(i >= 0 && score[i].points < p && size > 0)
    {
      score[i+1] = score[i];
      i--;
    }
    score[i+1] = s;
  }
}
void ScoreManager::SaveScore()
{
  std::ofstream file;
  file.open("score.txt",std::ofstream::out | std::ofstream::trunc);
  for(int i = 0; i < size;i++)
  {
    file << score[i].name << ":"<<score[i].points<<"\n";
  }
  file.close();
}
void ScoreManager::afficher()
{
  for(int i = 0;i < size;i++)
  {
    std::cout << i<<" => "<<score[i].name<<"   points="<<score[i].points<<std::endl;
  }
}
