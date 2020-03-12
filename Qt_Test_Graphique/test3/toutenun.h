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
#include <QMouseEvent>
#include <QLCDNumber>

#include "Terrain.h"
#include "Erreur.h"
#include "Node.h"
#include "Vector.h"
#include "PlayerController.h"
#include "niveaux.h"


class ToutEnUn : public QWidget
{
    Q_OBJECT

public:
    explicit ToutEnUn(int seed, QWidget *parent = 0);

    void GenererTerrain(std::string&);
    void GenererTerrain(Vector, int, int, int);
    void AjouterJoueur(PlayerController::TypeJ);
    void Afficher();
    void Interagir();
    void Mouvement(int);
    void NombreJoueur();
    bool PositionJoueur(Vector&);
    int getValeur();


protected:
    void mousePressEvent(QMouseEvent *event) override;

private:
    Terrain *T;
    PlayerController Joueurs[5];
    int nombreJ = 0;
    int x = 0;
    int y = 0;
    int point = 0;

    QLabel *j1;
    QSpinBox *valeur;
    QHBoxLayout *principal;
    QGridLayout *jeu;
    QVBoxLayout *option;
    QFormLayout *choix;
    QPushButton *valide;
    QFormLayout *score;
    QSpinBox *afficheScore;

};

#endif // TOUTENUN_H
