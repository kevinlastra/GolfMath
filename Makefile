
Files = Node.cpp Terrain.cpp Vector.cpp PlayerController.cpp GameMaster.cpp Erreur.cpp NoeudA.cpp
Main = test_Terrain.cpp
exec = test
flags = -Wall -ansi -pedantic

all: 
	g++ $(flags) $(Files) $(Main) -o $(exec)
mm:
	g++ testNoise.cpp -o MapMaker	
