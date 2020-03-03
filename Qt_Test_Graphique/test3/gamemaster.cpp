#include "gamemaster.h"

gameMaster::gameMaster()
{

    principal = new QVBoxLayout;
        titre = new QLabel("Golf Mathématique");
        principal->addWidget(titre);

        jouer = new QPushButton("Jouer");
        inutile = new QPushButton("Inutile");
        quitter = new QPushButton("Quitter");

        principal->addWidget(jouer);
        principal->addWidget(inutile);
        principal->addWidget(quitter);

    connect(quitter, SIGNAL(clicked()), qApp, SLOT(quit()));

    connect(jouer, SIGNAL(clicked()), this, SLOT(lancerOption()));

    setLayout(principal);
}

void gameMaster::lancerOption()
{
    nbJ_et_map *fenetreOption = new nbJ_et_map();
    fenetreOption->show();
}

