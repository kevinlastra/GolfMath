#ifndef JEU_H
#define JEU_H

#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QLayout>
#include <QBoxLayout>
#include <QDialog>
#include <QObject>
#include <QEvent>
#include <QKeyEvent>

#include "Node.h"
#include "Erreur.h"
#include "Vector.h"
#include "PlayerController.h"
#include "Terrain.h"
#include "nbj_et_map.h"

class Jeu : public QWidget
{
    Q_OBJECT

public:
    QKeyEvent *event;

    Jeu(int, int);

    void PrintMap(int player);
    void GenerateTerrain(std::string&);
    void GenerateTerrain(Vector, int, int, int);

    void AddPlayer(PlayerController::TypeJ t);
    void Interactuer(int);
    bool playerAtPos(Vector&);

protected:
    void keyPressEvent(QKeyEvent *event);

private:
    QGridLayout *grilleDeJeu;

    Terrain *T;
    PlayerController Players[5];
};

#endif // JEU_H
