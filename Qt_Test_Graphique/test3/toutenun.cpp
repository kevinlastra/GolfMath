#include "toutenun.h"

ToutEnUn::ToutEnUn(int seed, int joueur, int ia, QWidget *parent) : QWidget(parent)
{
    QPalette fond;
    fond.setBrush(backgroundRole(),QBrush(QColor(131, 156, 114)));
    setPalette(fond);

    principal = new QHBoxLayout;
    jeu = new QGridLayout;
    jeu->setSpacing(0);
    j1 = new QLabel;
    j2 = new QLabel;
    j3 = new QLabel;
    j4 = new QLabel;
    j1->setPixmap(QPixmap("../image/v2/j1.png"));
    j2->setPixmap(QPixmap("../image/v2/j2.png"));
    j3->setPixmap(QPixmap("../image/v2/j3.png"));
    j4->setPixmap(QPixmap("../image/v2/j4.png"));

    nombreJoueur = joueur;
    nombreIA = ia;

    score = new QFormLayout;

    for (int i = 1; i <= nombreJoueur; i++)
    {

        QString scorejoueur = "Score j";
        scorejoueur += QString::number(i);
        scorejoueur += " : ";
        switch (i)
        {
        case 1:
        {
            afficheScorej1 = new QSpinBox;
            afficheScorej1->setReadOnly(true);
            score->addRow(scorejoueur, afficheScorej1);
            break;
        }
        case 2:
        {
            afficheScorej2 = new QSpinBox;
            afficheScorej2->setReadOnly(true);
            score->addRow(scorejoueur, afficheScorej2);
            break;
        }
        case 3:
        {
            afficheScorej3 = new QSpinBox;
            afficheScorej3->setReadOnly(true);
            score->addRow(scorejoueur, afficheScorej3);
            break;
        }
        case 4:
        {
            afficheScorej4 = new QSpinBox;
            afficheScorej4->setReadOnly(true);
            score->addRow(scorejoueur, afficheScorej4);
            break;
        }
        }
    }

    std::string chemin = "/home/e20150002138/Bureau/GolfMath/testmap.txt";
    //GenererTerrain(chemin);
    GenererTerrain(Vector(40, 40), 10, 5, seed);
    Afficher();
    //NombreJoueur();
    //Interagir();


    principal->addLayout(jeu);
    principal->addLayout(score);

    scroll(10,10);

    setLayout(principal);
}



void ToutEnUn::GenererTerrain(std::string &s)
{
    T = new Terrain(s);
}



void ToutEnUn::GenererTerrain(Vector dim,int nbMove,int marge,int seed)
{
    T = new Terrain(seed,dim,nbMove,marge);
}



void ToutEnUn::AjouterJoueur(PlayerController::TypeJ t)
{
    QDialog *d = new QDialog();
    QFormLayout *debut = new QFormLayout;
    QSpinBox *pdebut = new QSpinBox;
    pdebut->setMinimum(1);
    pdebut->setMaximum(9);
    debut->addRow("Position de debut : ", pdebut);
    d->setLayout(debut);

    /*
    if(t==PlayerController::H)
    {
        std::cout << "start position?"<<std::endl;
    }
    */

    PlayerController p = PlayerController(t);
    p.SetPosAtTerrain(T->getStartPos());
    Joueurs[nombreJ] = p;
    nombreJ++;
}


void ToutEnUn::mousePressEvent(QMouseEvent *event)
{
    if (i > nombreJoueur)
    {
        i = 1;
        tour++;
    }
    x = (event->pos().x() - 8)/16;
    y = (event->pos().y() - 8)/16;
    Vector w(y, x);

    if (!(x <= -1 || x >= T->getLar()) &&
            !(y <= -1 || y >= T->getLon()))
    {
        if (T->getNode(w)->getType() == Node::end)
        {
            switch (i)
            {
            case 1 :
            {
                finij1 = true;
                QMessageBox::information(this, "Bravo !!", "Joueur 1 a terminé en " + QString::number(pointj1) + " coups.");
                break;
            }
            case 2 :
            {
                finij2 = true;
                QMessageBox::information(this, "Bravo !!", "Joueur 2 a terminé en " + QString::number(pointj2) + " coups.");
                break;
            }
            case 3 :
            {
                finij3 = true;
                QMessageBox::information(this, "Bravo !!", "Joueur 3 a terminé en " + QString::number(pointj3) + " coups.");
                break;
            }
            case 4 :
            {
                finij4 = true;
                QMessageBox::information(this, "Bravo !!", "Joueur 4 a terminé en " + QString::number(pointj4) + " coups.");
                break;
            }
            }
        }
        if ((finij1 && nombreJoueur == 1) ||
                (finij2 && finij1 && nombreJoueur == 2) ||
                (finij3 && finij2 && finij1 && nombreJoueur == 3) ||
                (finij4 && finij3 && finij2 && finij1 && nombreJoueur == 4))
        {
            QMessageBox::information(this, "FIN", "Belle partie c'était sympa!");
            Niveaux *niv = new Niveaux;
            niv->show();
            this->close();
        }
        if (tour == 1)
        {
            if (T->getNode(w)->getType() == Node::start)
            {
                Score(i);
                switch (i)
                {
                case 1:
                {
                    i++;
                    if (finij1)
                    {
                        break;
                    }
                    jeu->addWidget(j1, y, x);
                    j1->update();
                    jeu->update();
                    event->accept();
                    break;
                }
                case 2:
                {
                    i++;
                    if (finij2)
                    {
                        break;
                    }
                    jeu->addWidget(j2, y, x);
                    j2->update();
                    jeu->update();
                    event->accept();
                    break;
                }
                case 3:
                {
                    i++;
                    if (finij3)
                    {
                        break;
                    }
                    jeu->addWidget(j3, y, x);
                    j3->update();
                    jeu->update();
                    event->accept();
                    break;
                }
                case 4:
                {
                    i++;
                    if (finij4)
                    {
                        break;
                    }
                    jeu->addWidget(j4, y, x);
                    j4->update();
                    jeu->update();
                    event->accept();
                    break;
                }
                }
            }
            else
            {
                QMessageBox::critical(this, "Erreur", "Case injouable (probablement eau)");
            }
        }
        else
        {
            Score(i);
            if (T->getNode(w)->getType() != Node::eau &&
                    T->getNode(w)->getType() != Node::NONE)
            {
                switch (i)
                {
                case 1:
                {
                    i++;
                    if (finij1)
                    {
                        break;
                    }
                    jeu->addWidget(j1, y, x);
                    j1->update();
                    jeu->update();
                    event->accept();
                    break;
                }
                case 2:
                {
                    i++;
                    if (finij2)
                    {
                        break;
                    }
                    jeu->addWidget(j2, y, x);
                    j2->update();
                    jeu->update();
                    event->accept();
                    break;
                }
                case 3:
                {
                    i++;
                    if (finij3)
                    {
                        break;
                    }
                    jeu->addWidget(j3, y, x);
                    j3->update();
                    jeu->update();
                    event->accept();
                    break;
                }
                case 4:
                {
                    i++;
                    if (finij4)
                    {
                        break;
                    }
                    jeu->addWidget(j4, y, x);
                    j4->update();
                    jeu->update();
                    event->accept();
                    break;
                }
                }
            }
            else
            {
                QMessageBox::critical(this, "Erreur", "Case injouable (probablement eau)");
            }
        }
    }
    else
    {
        QMessageBox::critical(this, "Erreur", "En dehors de la grille!");
    }

}


void ToutEnUn::Score(int i)
{
    switch (i)
    {
    case 1:
    {
        if (finij1)
        {
            break;
        }
        afficheScorej1->setValue(++pointj1);
        if (pointj1 > 14)
        {
            QMessageBox::information(this, "Perdu", "Le joueur 1 a perdu");
            finij1 = true;
        }
        break;
    }
    case 2:
    {
        if (finij2)
        {
            break;
        }
        afficheScorej2->setValue(++pointj2);
        if (pointj2 > 14)
        {
            QMessageBox::information(this, "Perdu", "Le joueur 2 a perdu");
            finij2 = true;
        }
        break;
    }
    case 3:
    {
        if (finij3)
        {
            break;
        }
        afficheScorej3->setValue(++pointj3);
        if (pointj3 > 14)
        {
            QMessageBox::information(this, "Perdu", "Le joueur 3 a perdu");
            finij3 = true;
        }
        break;
    }
    case 4:
    {
        if (finij4)
        {
            break;
        }
        afficheScorej4->setValue(++pointj4);
        if (pointj4 > 14)
        {
            QMessageBox::information(this, "Perdu", "Le joueur 4 a perdu");
            finij4 = true;
        }
        break;
    }
    }

}


void ToutEnUn::Afficher()
{
    Erreur::print();
    for(int j = 0; j < T->getLar();j++)
    {
        for(int i = 0; i < T->getLon();i++)
        {
            Vector v(i,j);
            if(PositionJoueur(v))
            {
                QLabel *joueur = new QLabel();
                joueur->setPixmap(QPixmap("../image/v2/j1.png"));
                jeu->addWidget(joueur, i, j);
            }
            else
            {
                switch(T->getNode(v)->getType())
                {
                case Node::herbe:
                {
                    QString path = "../image/v2/green_";
                    path += QString::number(T->getNode(v)->getPorter());
                    path += ".jpg";
                    QLabel *herbe = new QLabel();
                    herbe->setPixmap(QPixmap(path));
                    jeu->addWidget(herbe, i, j);
                    break;
                }
                case Node::start:
                {
                    QString path = "../image/v2/start_";
                    path += QString::number(T->getNode(v)->getPorter());
                    path += ".jpg";
                    QLabel *start = new QLabel();
                    start->setPixmap(QPixmap(path));
                    jeu->addWidget(start, i, j);
                    break;
                }
                case Node::end:
                {
                    QLabel *trou = new QLabel();
                    trou->setPixmap(QPixmap("../image/v2/hole.jpg"));
                    jeu->addWidget(trou, i, j);
                    break;
                }
                case Node::sable:
                {
                    QString path = "../image/v2/green_";
                    path += QString::number(T->getNode(v)->getPorter());
                    path += ".jpg";
                    QLabel *sable = new QLabel();
                    sable->setPixmap(QPixmap(path));
                    jeu->addWidget(sable, i, j);
                    break;
                }
                default:
                {
                    QLabel *eau = new QLabel();
                    eau->setPixmap(QPixmap("../image/v2/water.jpg"));
                    jeu->addWidget(eau, i, j);
                    break;
                }
                }
            }
        }
    }
}




void ToutEnUn::Interagir()
{
    bool stop = false;
    //int nbcoup = 0;
    int Player = 0;
    while(!stop)
    {
        Mouvement(Player);

        if(Joueurs[Player].GetPos() == T->getTargetPos())
        {
            QMessageBox::information(this, "Victoire", "Tu as gagner!");
            stop = true;
        }

        Player++;
        if(Player == nombreJ)
            Player = 0;
    }
}



void ToutEnUn::Mouvement(int i)
{
    if (Joueurs[i].GetTypeJ()==PlayerController::H)
    {
        valeur->value();
    }
    else if (Joueurs[i].GetTypeJ()==PlayerController::IA)
    {
        valeur->setValue(Joueurs[i].iaJouer(T,T->getTargetPos()));
    }
    Vector npos(Joueurs[i].GetPos());
    int porter = T->getNode(Vector(npos.x,npos.y))->getPorter();
    Node* node;
    if (valide->isChecked())
    {
        switch(valeur->value())
        {
        case 8:
            node = T->getNode(Vector(npos.x,npos.y-porter));
            if(node != NULL && node->getType() != Node::eau && node->getType() != Node::NONE)
            {
                npos.y -= porter;
            }
            else
                Erreur(Erreur::MOVEMENT);
            break;
        case 2:
            node = T->getNode(Vector(npos.x,npos.y+porter));
            if(node != NULL && node->getType() != Node::eau && node->getType() != Node::NONE)
            {
                npos.y += porter;
            }
            else
                Erreur(Erreur::MOVEMENT);
            break;
        case 6:
            node = T->getNode(Vector(npos.x+porter,npos.y));
            //            std::cout <<"type:"<< node->getType() <<std::endl;
            if(node != NULL && node->getType() != Node::eau && node->getType() != Node::NONE)
            {
                npos.x += porter;
            }
            else
                Erreur(Erreur::MOVEMENT);
            break;
        case 4:
            node = T->getNode(Vector(npos.x-porter,npos.y));
            if(node != NULL && node->getType() != Node::eau && node->getType() != Node::NONE)
            {
                npos.x -= porter;
            }
            else
                Erreur(Erreur::MOVEMENT);
            break;
        case 7:
            node = T->getNode(Vector(npos.x-porter,npos.y-porter));
            if(node != NULL && node->getType() != Node::eau && node->getType() != Node::NONE)
            {
                npos.x -= porter;
                npos.y -= porter;
            }
            else
                Erreur(Erreur::MOVEMENT);
            break;
        case 9:
            node = T->getNode(Vector(npos.x+porter,npos.y-porter));
            if(node != NULL && node->getType() != Node::eau && node->getType() != Node::NONE)
            {
                npos.x += porter;
                npos.y -= porter;
            }
            else
                Erreur(Erreur::MOVEMENT);
            break;
        case 1:
            node = T->getNode(Vector(npos.x-porter,npos.y+porter));
            if(node != NULL && node->getType() != Node::eau && node->getType() != Node::NONE)
            {
                npos.x -= porter;
                npos.y += porter;
            }
            else
                Erreur(Erreur::MOVEMENT);
            break;
        case 3:
            node = T->getNode(Vector(npos.x+porter,npos.y+porter));
            if(node != NULL && node->getType() != Node::eau && node->getType() != Node::NONE)
            {
                npos.x += porter;
                npos.y += porter;
            }
            else
                Erreur(Erreur::MOVEMENT);
            break;

        }
    }
    Joueurs[i].SetPos(npos);
    Joueurs[i].PCoup();
}



void ToutEnUn::NombreJoueur()
{
    QDialog *nbj = new QDialog();
    QFormLayout *requete = new QFormLayout;
    QSpinBox *nombre = new QSpinBox;
    nombre->setMinimum(1);
    nombre->setMaximum(4);
    requete->addRow("Combien de joueur ? ", nombre);
    nbj->setLayout(requete);

    /*
    int n = -1;
    char c;
    while(true)
    {
        std::cout << "combien de joueurs[0-4]?" << std::endl;
        std::cin >> n;
        if(n >= 0 && n <= 4)
            break;
        Erreur(Erreur::ARGUMENT);
        Erreur::print();
    }
    */

    for(int i = 0;i < nombre->value();i++)
    {
        AjouterJoueur(PlayerController::H);
    }

    /*
    std::cout << "voulez-vous une IA ? \n y/n" <<std::endl ;
    std::cin >> c;
    if (c == 'y'){
        AjouterJoueur(PlayerController::IA);
    }
    */
}



bool ToutEnUn::PositionJoueur(Vector &v)
{
    for(int i = 0;i < nombreJ;i++)
    {
        if(Joueurs[i].GetPos() == v)
        {
            return true;
        }
    }
    return false;
}


int ToutEnUn::getValeur()
{
    return valeur->value();
}

