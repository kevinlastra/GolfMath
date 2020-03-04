#include "jeu.h"


Jeu::Jeu(int nbJoueur, int map)
{
    if (map == 1)
    {
        std::string mapPath = "testmap.txt";
        GenerateTerrain(mapPath);
    }
    else
    {
        GenerateTerrain(Vector(40, 40), 10, 5, -1);
    }
    Interactuer(nbJoueur);
}

int player = 0;

void Jeu::PrintMap(int player)
{
    grilleDeJeu = new QGridLayout;
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
    setLayout(grilleDeJeu);
}

void Jeu::Interactuer(int nbJoueur)
{
    bool stop = false;
    while (!stop)
    {
        PrintMap(player);

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

void Jeu::keyPressEvent(QKeyEvent *event)
{
    grilleDeJeu->update();
    Vector npos(Players[player].GetPos());
    Node* node;
    int portee = T->getNode(Vector(npos.x, npos.y))->getPorter();
    if (event->key() == Qt::Key_E)
    {
        node = T->getNode(Vector(npos.x - portee, npos.y + portee));
        if (node != NULL && node->getType() != Node::eau && node->getType() != Node::NONE)
        {
            npos.x -= portee;
            npos.y += portee;
        }
        else
        {
            printf("erreur movement");
        }
    }

    if (event->key() == Qt::Key_R)
    {
        node = T->getNode(Vector(npos.x, npos.y + portee));
        if (node != NULL && node->getType() != Node::eau && node->getType() != Node::NONE)
        {
            npos.y += portee;
        }
        else
        {
            printf("erreur movement");
        }
    }

    if (event->key() == Qt::Key_T)
    {
        node = T->getNode(Vector(npos.x + portee, npos.y + portee));
        if (node != NULL && node->getType() != Node::eau && node->getType() != Node::NONE)
        {
            npos.x += portee;
            npos.y += portee;
        }
        else
        {
            printf("erreur movement");
        }
    }

    if (event->key() == Qt::Key_D)
    {
        node = T->getNode(Vector(npos.x - portee, npos.y));
        if (node != NULL && node->getType() != Node::eau && node->getType() != Node::NONE)
        {
            npos.x -= portee;
        }
        else
        {
            printf("erreur movement");
        }
    }

    if (event->key() == Qt::Key_G)
    {
        node = T->getNode(Vector(npos.x - portee, npos.y + portee));
        if (node != NULL && node->getType() != Node::eau && node->getType() != Node::NONE)
        {
            npos.x -= portee;
            npos.y += portee;
        }
        else
        {
            printf("erreur movement");
        }
    }

    if (event->key() == Qt::Key_C)
    {
        node = T->getNode(Vector(npos.x - portee, npos.y - portee));
        if (node != NULL && node->getType() != Node::eau && node->getType() != Node::NONE)
        {
            npos.x -= portee;
            npos.y -= portee;
        }
        else
        {
            printf("erreur movement");
        }
    }

    if (event->key() == Qt::Key_V)
    {
        node = T->getNode(Vector(npos.x, npos.y - portee));
        if (node != NULL && node->getType() != Node::eau && node->getType() != Node::NONE)
        {
            npos.y -= portee;
        }
        else
        {
            printf("erreur movement");
        }
    }

    if (event->key() == Qt::Key_B)
    {
        node = T->getNode(Vector(npos.x + portee, npos.y - portee));
        if (node != NULL && node->getType() != Node::eau && node->getType() != Node::NONE)
        {
            npos.x += portee;
            npos.y -= portee;
        }
        else
        {
            printf("erreur movement");
        }
    }
    Players[player].SetPos(npos);
    Players[player].PCoup();
}


bool Jeu::playerAtPos(Vector &v)
{
    for (int i = 0; i < nbJ_et_map().nbJoueur->value(); ++i)
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
