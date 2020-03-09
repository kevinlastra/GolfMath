#include "toutenun.h"

ToutEnUn::ToutEnUn(QWidget *parent) : QMainWindow(parent)
{
    QWidget *zoneCentral = new QWidget;

    principal = new QHBoxLayout;
    jeu = new QGridLayout;
    jeu->setSpacing(0);

    option = new QVBoxLayout;
    choix = new QFormLayout;
    valeur = new QSpinBox;
    valeur->setMaximum(9);
    valeur->setMinimum(1);
    valide = new QPushButton("  Check!  ");
    choix->addRow("Valeur : ", valeur);
    choix->addWidget(valide);
    option->addLayout(choix);

    std::string chemin = "/home/e20150002138/Bureau/GolfMath/testmap.txt";
    GenererTerrain(chemin);
    //GenererTerrain(Vector(50, 50), 10, 5, -1);
    Afficher();
    //NombreJoueur();
    //Interagir();

    principal->addLayout(jeu);
    principal->addLayout(option);

    zoneCentral->setLayout(principal);
    setCentralWidget(zoneCentral);
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
    Afficher();

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



void ToutEnUn::Afficher()
{
    jeu->update();
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
                    QString path = "../image/v2/start_";
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
        Afficher();
        Mouvement(Player);

        if(Joueurs[Player].GetPos() == T->getTargetPos())
        {
            Afficher();
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
