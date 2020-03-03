#include "nbj_et_map.h"

nbJ_et_map::nbJ_et_map()
{
    nbJoueur = new QLineEdit;
    map = new QLineEdit;

    option = new QFormLayout;
        option->addRow("Combien de Joueur : (jusqu'à 4 joueurs)", nbJoueur);
        option->addRow("Quel carte : (0 aléatoire, 1 test)", map);

        lancerJeu = new QPushButton("Lancer jeu");
        option->addWidget(lancerJeu);

    QObject::connect(lancerJeu, SIGNAL(clicked()), this, SLOT(lancer()));

    setLayout(option);
}

void nbJ_et_map::lancer()
{
    Jeu *carte = new Jeu();

    if ((map->text() == "0" || map->text() == "1") &&
            (nbJoueur->text() >= "1" && nbJoueur->text() <= "4"))
    {
        carte->show();
    }
    else
    {
        QMessageBox::critical(this, "Erreur !!", "Vous n'avez pas bien défini les joueurs et/ou la map!");
    }
}
