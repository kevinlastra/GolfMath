#include "nbj_et_map.h"

nbJ_et_map::nbJ_et_map()
{
    nb = new QSpinBox;
    map = new QSpinBox;
    nb->setMaximum(4);
    nb->setMinimum(1);
    map->setMaximum(1);
    map->setMinimum(0);

    option = new QFormLayout;
        option->addRow("Combien de Joueur : ", nb);
        option->addRow("Quel carte : ", map);

        lancerJeu = new QPushButton("Lancer jeu");
        option->addWidget(lancerJeu);

    QObject::connect(lancerJeu, SIGNAL(clicked()), this, SLOT(lancer()));

    setLayout(option);
}

void nbJ_et_map::lancer()
{
    Jeu *carte = new Jeu(nb->value(), map->value());
    carte->show();
}
