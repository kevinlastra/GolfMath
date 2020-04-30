#include "toutenun.h"

ToutEnUn::ToutEnUn(int seed, int joueur, int ia, QWidget *parent) : QWidget(parent)
{
    setWindowIcon(QIcon("./image/ballegolf.png"));
    setWindowTitle("Golf Mathématique");

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
    j1->setPixmap(QPixmap("./image/v2/j1.png"));
    j2->setPixmap(QPixmap("./image/v2/j2.png"));
    j3->setPixmap(QPixmap("./image/v2/j3.png"));
    j4->setPixmap(QPixmap("./image/v2/j4.png"));


    QString cp = "./image/v2/cp.png";
    possibleCoup1 = new QLabel;
    possibleCoup2 = new QLabel;
    possibleCoup3 = new QLabel;
    possibleCoup4 = new QLabel;
    possibleCoup5 = new QLabel;
    possibleCoup6 = new QLabel;
    possibleCoup7 = new QLabel;
    possibleCoup8 = new QLabel;
    possibleCoup1->setPixmap(QPixmap(cp));
    possibleCoup2->setPixmap(QPixmap(cp));
    possibleCoup3->setPixmap(QPixmap(cp));
    possibleCoup4->setPixmap(QPixmap(cp));
    possibleCoup5->setPixmap(QPixmap(cp));
    possibleCoup6->setPixmap(QPixmap(cp));
    possibleCoup7->setPixmap(QPixmap(cp));
    possibleCoup8->setPixmap(QPixmap(cp));

    nombreJoueur = joueur;
    if (joueur < 4)
    {
        nombreJoueur += ia;
        joueurIA = ia;
    }

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
            afficheScorej1->setPalette(QColor(200, 0, 0));
            score->addRow(scorejoueur, afficheScorej1);
            break;
        }
        case 2:
        {
            afficheScorej2 = new QSpinBox;
            afficheScorej2->setReadOnly(true);
            afficheScorej2->setPalette(QColor(0, 200, 200));
            score->addRow(scorejoueur, afficheScorej2);
            break;
        }
        case 3:
        {
            afficheScorej3 = new QSpinBox;
            afficheScorej3->setReadOnly(true);
            afficheScorej3->setPalette(QColor(200, 200, 0));
            score->addRow(scorejoueur, afficheScorej3);
            break;
        }
        case 4:
        {
            afficheScorej4 = new QSpinBox;
            afficheScorej4->setReadOnly(true);
            afficheScorej4->setPalette(QColor(0, 200, 0));
            score->addRow(scorejoueur, afficheScorej4);
            break;
        }
        }
    }

    tourduj = new QLabel;
    tourduj->setText("C'est au joueur 1");
    score->addWidget(tourduj);

    GenererTerrain(Vector(40, 40), 10, 5, seed);
    Afficher();
    noeud = new Node[100];

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


void ToutEnUn::mousePressEvent(QMouseEvent *event)
{

    x = (event->pos().x() - 12)/16;
    y = (event->pos().y() - 12)/16;
    Vector w(y, x);

    if (!(x <= -1 || x >= T->getLar()) &&
            !(y <= -1 || y >= T->getLon()))
    {

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
                    posj1.x = w.x;
                    posj1.y = w.y;
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
                    if (joueurIA == 0 || nombreJoueur > 2)
                    {
                        posj2.x = w.x;
                        posj2.y = w.y;
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
                    if (joueurIA == 0 || nombreJoueur > 3)
                    {
                        posj3.x = w.x;
                        posj3.y = w.y;
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
                    if (joueurIA == 0 || nombreJoueur == 4)
                    {
                        posj4.x = w.x;
                        posj4.y = w.y;
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
                QMessageBox::critical(this, "Attention", "Vous ne pouvez pas allez sur cette case!");
            }
        }
        else
        {
            Score(i);
            if (T->getNode(w)->getType() != Node::eau &&
                    T->getNode(w)->getType() != Node::NONE &&
                    ((Mouvement(w, posj1) && i == 1) ||
                     (Mouvement(w, posj2) && i == 2) ||
                     (Mouvement(w, posj3) && i == 3) ||
                     (Mouvement(w, posj3) && i == 4)))
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

                switch (i)
                {
                case 1:
                {
                    if (finij1)
                    {
                        i++;
                        break;
                    }
                    posj1.x = w.x;
                    posj1.y = w.y;
                    i++;
                    jeu->addWidget(j1, y, x);
                    j1->update();
                    jeu->update();
                    event->accept();
                    break;
                }
                case 2:
                {
                    if (finij2)
                    {
                        i++;
                        break;
                    }
                    if (joueurIA == 0 || nombreJoueur > 2)
                    {
                        posj2.x = w.x;
                        posj2.y = w.y;
                    }
                    i++;
                    jeu->addWidget(j2, y, x);
                    j2->update();
                    jeu->update();
                    event->accept();
                    break;
                }
                case 3:
                {
                    if (finij3)
                    {
                        i++;
                        break;
                    }
                    if (joueurIA == 0 || nombreJoueur > 3)
                    {
                        posj3.x = w.x;
                        posj3.y = w.y;
                    }
                    i++;
                    jeu->addWidget(j3, y, x);
                    j3->update();
                    jeu->update();
                    event->accept();
                    break;
                }
                case 4:
                {
                    if (finij4)
                    {
                        i++;
                        break;
                    }
                    if (joueurIA == 0 || nombreJoueur == 4)
                    {
                        posj4.x = w.x;
                        posj4.y = w.y;
                    }
                    i++;
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
                QMessageBox::critical(this, "Attention", "Vous ne pouvez pas allez sur cette case!");
            }
        }
    }
    else
    {
        QMessageBox::critical(this, "Erreur", "En dehors de la grille!");
    }
    if (joueurIA == 1)
    {
        DeplacementIA(nombreJoueur);
        jeu->update();
        i++;
    }
    if (i > nombreJoueur)
    {
        i = 1;
        tour++;
    }
    if (finij1 && i == 1) i++;
    if (finij2 && i == 2) i++;
    if (finij3 && i == 3) i++;
    if (finij4 && i == 4) i++;
    ProchainCoup();
    QString tj = "C'est au joueur ";
    tj += QString::number(i);
    tourduj->setText(tj);
    tourduj->update();

}

void ToutEnUn::DeplacementIA(int p)
{
    noeud = cheminPlusCourt(T, T->getNode(T->getStartPos()), T->getNode(T->getTargetPos()));
    Score(i);
    switch (p)
    {
    case 2:
    {
        IADeplacement(T, noeud, manche, posj2);
        if (tour == 1)
        {
            posj2.y = posj1.y;
            posj2.x = posj1.x;
        }
        jeu->addWidget(j2, posj2.x, posj2.y);
        j2->update();
        jeu->update();
        break;
    }
    case 3:
    {
        IADeplacement(T, noeud, i, posj3);
        if (tour == 1)
        {
            posj3.x = posj2.x;
            posj3.y = posj2.y;
        }
        jeu->addWidget(j3, posj3.y, posj3.x);
        j3->update();
        jeu->update();
        break;
    }
    case 4:
    {
        IADeplacement(T, noeud, i, posj4);
        if (tour == 1)
        {
            posj4.x = posj3.x;
            posj4.y = posj3.y;
        }
        jeu->addWidget(j4, posj4.y, posj4.x);
        j4->update();
        jeu->update();
        break;
    }
    }
    manche++;
}

void ToutEnUn::ProchainCoup()
{
    if(tour > 1)
    {
        switch (i)
        {
        case 1:
        {
            Coup(posj1);
            jeu->update();
            break;
        }
        case 2:
        {
            Coup(posj2);
            jeu->update();
            break;
        }
        case 3:
        {
            Coup(posj3);
            jeu->update();
            break;
        }
        case 4:
        {
            Coup(posj4);
            jeu->update();
            break;
        }
        }
    }
}

void ToutEnUn::Coup(Vector position)
{
    jeu->addWidget(possibleCoup1, position.x - T->getNode(position)->getPorter(), position.y - T->getNode(position)->getPorter());
    jeu->addWidget(possibleCoup2, position.x - T->getNode(position)->getPorter(), position.y);
    jeu->addWidget(possibleCoup3, position.x, position.y - T->getNode(position)->getPorter());
    jeu->addWidget(possibleCoup4, position.x + T->getNode(position)->getPorter(), position.y + T->getNode(position)->getPorter());
    jeu->addWidget(possibleCoup5, position.x + T->getNode(position)->getPorter(), position.y);
    jeu->addWidget(possibleCoup6, position.x, position.y + T->getNode(position)->getPorter());
    jeu->addWidget(possibleCoup7, position.x + T->getNode(position)->getPorter(), position.y - T->getNode(position)->getPorter());
    jeu->addWidget(possibleCoup8, position.x - T->getNode(position)->getPorter(), position.y + T->getNode(position)->getPorter());
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


bool ToutEnUn::Mouvement(Vector positionDemande, Vector positionPrecedente)
{
    return ((positionDemande.x == positionPrecedente.x - T->getNode(positionPrecedente)->getPorter() && positionDemande.y == positionPrecedente.y) ||
            (positionDemande.x == positionPrecedente.x + T->getNode(positionPrecedente)->getPorter() && positionDemande.y == positionPrecedente.y) ||
            (positionDemande.y == positionPrecedente.y - T->getNode(positionPrecedente)->getPorter() && positionDemande.x == positionPrecedente.x) ||
            (positionDemande.y == positionPrecedente.y + T->getNode(positionPrecedente)->getPorter() && positionDemande.x == positionPrecedente.x) ||
            (positionDemande.x == positionPrecedente.x - T->getNode(positionPrecedente)->getPorter() && positionDemande.y == positionPrecedente.y - T->getNode(positionPrecedente)->getPorter()) ||
            (positionDemande.x == positionPrecedente.x + T->getNode(positionPrecedente)->getPorter() && positionDemande.y == positionPrecedente.y + T->getNode(positionPrecedente)->getPorter()) ||
            (positionDemande.y == positionPrecedente.y - T->getNode(positionPrecedente)->getPorter() && positionDemande.x == positionPrecedente.x + T->getNode(positionPrecedente)->getPorter()) ||
            (positionDemande.y == positionPrecedente.y + T->getNode(positionPrecedente)->getPorter() && positionDemande.x == positionPrecedente.x - T->getNode(positionPrecedente)->getPorter()));
}


void ToutEnUn::Afficher()
{
    Erreur::print();
    for(int j = 0; j < T->getLar();j++)
    {
        for(int i = 0; i < T->getLon();i++)
        {
            Vector v(i,j);
            switch(T->getNode(v)->getType())
            {
            case Node::herbe:
            {
                QString path = "./image/v2/green_";
                path += QString::number(T->getNode(v)->getPorter());
                path += ".jpg";
                QLabel *herbe = new QLabel();
                herbe->setPixmap(QPixmap(path));
                jeu->addWidget(herbe, i, j);
                break;
            }
            case Node::start:
            {
                QString path = "./image/v2/start_";
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
                trou->setPixmap(QPixmap("./image/v2/hole.jpg"));
                jeu->addWidget(trou, i, j);
                break;
            }
            case Node::sable:
            {
                QString path = "./image/v2/green_";
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
                eau->setPixmap(QPixmap("./image/v2/water.jpg"));
                jeu->addWidget(eau, i, j);
                break;
            }
            }

        }
    }

}

void ToutEnUn::IADeplacement(Terrain *&T, Node* noeud, int k, Vector & pjIA){
    std::cout<<"debut fonction"<<std::endl;

    int porter = T->getNode(pjIA)->getPorter();
    Vector w = noeud[k].getPos();
    int i=0;
    while(noeud[i].getType() != Node::NONE){
        std::cout<<noeud[i].getPos().x<<" "<<noeud[i].getPos().y<<std::endl;
        i++;
    }
    std::cout<<"je suis en : "<<pjIA.x<<" "<<pjIA.y<<std::endl;
    std::cout<<"je veux aller en : "<<noeud[k].getPos().x<<" "<<noeud[k].getPos().y<<std::endl;

    if(w.x == pjIA.x+porter && w.y == pjIA.y+porter){
        pjIA.x += porter;
        pjIA.y += porter;
        std::cout<<"3"<<std::endl;
    }
    else if(w.x == pjIA.x+porter && w.y == pjIA.y-porter){
        pjIA.x += porter;
        pjIA.y -= porter;
        std::cout<<"9"<<std::endl;
    }
    else if(w.x == pjIA.x-porter && w.y == pjIA.y+porter){
        pjIA.x -= porter;
        pjIA.y += porter;
        std::cout<<"1"<<std::endl;
    }
    else if(w.x == pjIA.x-porter && w.y == pjIA.y-porter){
        pjIA.x -= porter;
        pjIA.y -= porter;
        std::cout<<"7"<<std::endl;
    }
    else if(w.x == pjIA.x+porter){
        pjIA.x += porter;
        std::cout<<"6"<<std::endl;
    }
    else if(w.x == pjIA.x-porter){
        pjIA.x -= porter;
        std::cout<<"4"<<std::endl;
    }
    else if(w.y == pjIA.y+porter){
        pjIA.y += porter;
        std::cout<<"2"<<std::endl;
    }
    else if(w.y == pjIA.y-porter){
        pjIA.y -= porter;
        std::cout<<"8"<<std::endl;
    }

}

