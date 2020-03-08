#include <iostream>
#include <string>

class ScoreManager
{
 private:
  
  struct Score
  {
    std::string name;
    int points;
  };
  int size = 0;
  Score score[10];
 public:
  ScoreManager();
  Score* GetScore();
  int getsize();
  bool inscore(int);
  void sortnewscore(std::string,int);
  void SaveScore();
  void afficher();
};
