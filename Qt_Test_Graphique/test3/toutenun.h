#ifndef TOUTENUN_H
#define TOUTENUN_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QBoxLayout>
#include <QFormLayout>
#include <QPushButton>
#include <QSpinBox>
#include <QLabel>
#include <QMessageBox>
#include <QLineEdit>
#include <stdio.h>
#include <stdlib.h>
#include <string>

#include "Terrain.h"
#include "Erreur.h"
#include "Node.h"
#include "Vector.h"
#include "PlayerController.h"


class ToutEnUn : public QMainWindow
{
    Q_OBJECT

public:
    explicit ToutEnUn(QWidget *parent = nullptr);

    void GenererTerrain(std::string&);
    void GenererTerrain(Vector, int, int, int);
    void AjouterJoueur(PlayerController::TypeJ);
    void Afficher();
    void Interagir();
    void Mouvement(int);
    void NombreJoueur();
    bool PositionJoueur(Vector&);

private:
    Terrain *T;
    PlayerController Joueurs[5];
    int nombreJ = 0;

    QHBoxLayout *principal;
    QGridLayout *jeu;
    QVBoxLayout *option;
    QFormLayout *choix;
    QSpinBox *valeur;
    QPushButton *valide;

};

#endif // TOUTENUN_H
