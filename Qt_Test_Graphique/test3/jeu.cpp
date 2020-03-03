#include "jeu.h"

Jeu::Jeu()
{
    layImage = new QVBoxLayout;
        image = new QLabel;
        image->setPixmap(QPixmap("/home/e20150002138/Bureau/GolfMath/SDL_Test_Graphique/golfeur.png"));

        layImage->addWidget(image);

    setLayout(layImage);
}
