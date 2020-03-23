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
#include <QKeyEvent>
#include <QScrollArea>
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
    explicit ToutEnUn(int seed, int joueur, int ia, QWidget *parent = 0);

    void GenererTerrain(std::string&);
    void GenererTerrain(Vector, int, int, int);
    void AjouterJoueur(PlayerController::TypeJ);
    void Afficher();
    void Interagir();
    void Mouvement(int);
    void NombreJoueur();
    bool PositionJoueur(Vector&);
    int getValeur();
    void Score(int);


protected:
    void mousePressEvent(QMouseEvent *event) override;

private:
    Terrain *T;
    PlayerController Joueurs[5];
    int nombreJ = 0;
    int x = 0;
    int y = 0;
    int i = 1;
    int nombreJoueur;
    int nombreIA;
    int tour = 1;
    int pointj1 = 0;
    int pointj2 = 0;
    int pointj3 = 0;
    int pointj4 = 0;
    bool finij1 = false;
    bool finij2 = false;
    bool finij3 = false;
    bool finij4 = false;

    QLabel *j1;
    QLabel *j2;
    QLabel *j3;
    QLabel *j4;
    QSpinBox *valeur;
    QHBoxLayout *principal;
    QGridLayout *jeu;
    QVBoxLayout *option;
    QFormLayout *choix;
    QPushButton *valide;
    QFormLayout *score;
    QSpinBox *afficheScorej1;
    QSpinBox *afficheScorej2;
    QSpinBox *afficheScorej3;
    QSpinBox *afficheScorej4;

};

#endif // TOUTENUN_H
