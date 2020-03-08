#include "jeu.h"


Jeu::Jeu(int nbJoueur, int map)
{
    principal = new QHBoxLayout;
        QVBoxLayout *requete = new QVBoxLayout;
            position = new QSpinBox;
            position->setMaximum(9);
            position->setMinimum(1);
            QPushButton *valide = new QPushButton("Update");
            requete->addWidget(position);
            requete->addWidget(valide);
            grilleDeJeu = new QGridLayout;
        principal->addLayout(requete);

    if (map == 0)
    {
        std::string mapPath = "testmap.txt";
        GenerateTerrain(mapPath);
    }
    else
    {
        GenerateTerrain(Vector(40, 40), 10, 5, -1);
    }
    requeteNBJ();
    Interactuer(nbJoueur);
}


void Jeu::PrintMap(int player)
{
    Erreur::print();
    for (int j = 0; j < T->getLar(); ++j)
    {
        for (int i = 0; i < T->getLon(); ++i)
        {
            Vector v(i, j);
            if (playerAtPos(v))
            {
                QString perso = "../image/v2/j";
                perso += player;
                perso += ".png";
                QLabel *joueur = new QLabel;
                joueur->setPixmap(QPixmap(perso));
                grilleDeJeu->addWidget(joueur, i, j);
            }
            else
            {
                switch (T->getNode(v)->getType())
                {
                case Node::start:
                {
                    QString numStart = "../image/v2/start_";
                    numStart += T->getNode(v)->getPorter();
                    numStart += ".jpg";
                    QLabel *debut = new QLabel;
                    debut->setPixmap(QPixmap(numStart));
                    grilleDeJeu->addWidget(debut, i, j);
                    break;
                }
                case Node::end:
                {
                    QString hole = "../image/v2/hole.jpg";
                    QLabel *fin = new QLabel;
                    fin->setPixmap(QPixmap(hole));
                    grilleDeJeu->addWidget(fin, i, j);
                    break;
                }
                case Node::herbe:
                {
                    QString numHerbe = "../image/v2/green_";
                    numHerbe += T->getNode(v)->getPorter();
                    numHerbe += ".jpg";
                    QLabel *green = new QLabel;
                    green->setPixmap(QPixmap(numHerbe));
                    grilleDeJeu->addWidget(green, i, j);
                    break;
                }
                default:
                {
                    QString eau = "../image/v2/water.jpg";
                    QLabel *water = new QLabel;
                    water->setPixmap(QPixmap(eau));
                    grilleDeJeu->addWidget(water, i, j);
                    break;
                }
                }
            }
        }
    }
    principal->addLayout(grilleDeJeu);
}

void Jeu::Interactuer(int nbJoueur)
{
    int player = 0;
    bool stop = false;
    while (!stop)
    {
        PrintMap(player);
        requeteMouvement(player);

        if (Players[player].GetPos() == T->getTargetPos())
        {
            PrintMap(player);
            QString victoire = "Le joueur ";
            victoire += player;
            victoire += " a gagné la partie en ";
            victoire += Players[player].GetPCoup();
            victoire += "coups!!";
            QMessageBox::information(this, "GAGNER !", victoire);
            stop = true;
        }

        player++;
        if (player ==  nbJoueur)
        {
            player = 0;
        }
    }
}

void Jeu::requeteNBJ()
{
    for (int i = 0; i < nbJ_et_map().nb->value(); i++)
    {
        AddPlayer(PlayerController::H);
    }
}

void Jeu::requeteMouvement(int i)
{
    grilleDeJeu->update();
    Vector npos(Players[i].GetPos());
    Node* node;
    int portee = T->getNode(Vector(npos.x, npos.y))->getPorter();
    if (position->value() == 1)
    {
        node = T->getNode(Vector(npos.x - portee, npos.y + portee));
        if ((node != NULL) && (node->getType() != Node::eau) && (node->getType() != Node::NONE))
        {
            npos.x -= portee;
            npos.y += portee;
        }
        else
        {
            printf("erreur movement");
        }
    }

    if (position->value() == 2)
    {
        node = T->getNode(Vector(npos.x, npos.y + portee));
        if ((node != NULL) && (node->getType() != Node::eau) && (node->getType() != Node::NONE))
        {
            npos.y += portee;
        }
        else
        {
            printf("erreur movement");
        }
    }

    if (position->value() == 3)
    {
        node = T->getNode(Vector(npos.x + portee, npos.y + portee));
        if ((node != NULL) && (node->getType() != Node::eau) && (node->getType() != Node::NONE))
        {
            npos.x += portee;
            npos.y += portee;
        }
        else
        {
            printf("erreur movement");
        }
    }

    if (position->value() == 4)
    {
        node = T->getNode(Vector(npos.x - portee, npos.y));
        if ((node != NULL) && (node->getType() != Node::eau) && (node->getType() != Node::NONE))
        {
            npos.x -= portee;
        }
        else
        {
            printf("erreur movement");
        }
    }

    if (position->value() == 6)
    {
        node = T->getNode(Vector(npos.x - portee, npos.y + portee));
        if ((node != NULL) && (node->getType() != Node::eau) && (node->getType() != Node::NONE))
        {
            npos.x -= portee;
            npos.y += portee;
        }
        else
        {
            printf("erreur movement");
        }
    }

    if (position->value() == 7)
    {
        node = T->getNode(Vector(npos.x - portee, npos.y - portee));
        if ((node != NULL) && (node->getType() != Node::eau) && (node->getType() != Node::NONE))
        {
            npos.x -= portee;
            npos.y -= portee;
        }
        else
        {
            printf("erreur movement");
        }
    }

    if (position->value() == 8)
    {
        node = T->getNode(Vector(npos.x, npos.y - portee));
        if ((node != NULL) && (node->getType() != Node::eau) && (node->getType() != Node::NONE))
        {
            npos.y -= portee;
        }
        else
        {
            printf("erreur movement");
        }
    }

    if (position->value() == 9)
    {
        node = T->getNode(Vector(npos.x + portee, npos.y - portee));
        if ((node != NULL) && (node->getType() != Node::eau) && (node->getType() != Node::NONE))
        {
            npos.x += portee;
            npos.y -= portee;
        }
        else
        {
            printf("erreur movement");
        }
    }
    Players[i].SetPos(npos);
    Players[i].PCoup();
}


bool Jeu::playerAtPos(Vector &v)
{
    for (int i = 0; i < nbJ_et_map().nb->value(); ++i)
    {
        if (Players[i].GetPos() == v)
        {
            return true;
        }
    }
    return false;
}

void Jeu::GenerateTerrain(std::string &s)
{
    T = new Terrain(s);
}

void Jeu::GenerateTerrain(Vector dim, int nbMove, int marge, int seed)
{
    T = new Terrain(seed, dim, nbMove, marge);
}

void Jeu::AddPlayer(PlayerController::TypeJ t)
{
    PrintMap(0);
    if (t == PlayerController::H)
    {
        QDialog *position = new QDialog(this);
            QLineEdit *pos = new QLineEdit;
            QFormLayout *demande = new QFormLayout;
            demande->addRow("Position de debut :", pos);
            position->setLayout(demande);
        PlayerController p = PlayerController(t);
        p.SetPosAtTerrain(T->getStartPos());
    }
}
