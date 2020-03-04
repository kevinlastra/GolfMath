#include "nbj_et_map.h"

nbJ_et_map::nbJ_et_map()
{
    nbJoueur = new QSpinBox;
    map = new QSpinBox;
    nbJoueur->setMaximum(4);
    nbJoueur->setMinimum(1);
    map->setMaximum(1);
    map->setMinimum(0);

    option = new QFormLayout;
        option->addRow("Combien de Joueur : ", nbJoueur);
        option->addRow("Quel carte : ", map);

        lancerJeu = new QPushButton("Lancer jeu");
        option->addWidget(lancerJeu);

    QObject::connect(lancerJeu, SIGNAL(clicked()), this, SLOT(lancer()));

    setLayout(option);
}

void nbJ_et_map::lancer()
{
    Jeu *carte = new Jeu(nbJoueur->value(), map->value());
    carte->show();
}
