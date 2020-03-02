#include <QApplication>
#include <QApplicationStateChangeEvent>
#include <QPushButton>
#include <QBoxLayout>
#include <QLabel>
#include <QImage>
#include <QPixmap>
#include "mafenetre.h"
#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget fenetre;
        QVBoxLayout *fenPrinc = new QVBoxLayout;
        QPushButton *jouer = new QPushButton("Jouer");
        QPushButton *quitter = new QPushButton("Quitter");
        fenPrinc->addWidget(jouer);
        fenPrinc->addWidget(quitter);

    QDialog secondeFenetre(&fenetre);
        secondeFenetre.setModal(true);
        QGridLayout *lay = new QGridLayout;
        lay->setSpacing(0);
        for (int i = 0; i <= 35; i++){
            for (int j = 0; j <= 64; j++){
                if ((i >= 12 && i <= 14) && (j >= 10 && j <= 12)){
                    QLabel *image = new QLabel();
                    image->setPixmap(QPixmap("/home/benjamin/Bureau/Projet/GolfMath/Qt_Test_Graphique/testoc/v2/start_1.jpg"));
                    lay->addWidget(image, i, j);
                }
                else if (i == 28 && j == 50){
                    QLabel *image = new QLabel();
                    image->setPixmap(QPixmap("/home/benjamin/Bureau/Projet/GolfMath/Qt_Test_Graphique/testoc/v2/hole.jpg"));
                    lay->addWidget(image, i, j);
                }
                else if (((i >= 5 && i <= 20) && (j >= 5 && j <= 60)) ||
                         (((i >= 5) && (i <= 30)) && ((j >= 40) && (j <= 60)))){
                    QLabel *image = new QLabel();
                    image->setPixmap(QPixmap("/home/benjamin/Bureau/Projet/GolfMath/Qt_Test_Graphique/testoc/v2/green_1.jpg"));
                    lay->addWidget(image, i, j);
                }
                else {
                    QLabel *image = new QLabel();
                    image->setPixmap(QPixmap("/home/benjamin/Bureau/Projet/GolfMath/Qt_Test_Graphique/testoc/v2/water.jpg"));
                    lay->addWidget(image, i, j);
                }
            }
        }
        QLabel *player1 = new QLabel();
        player1->setPixmap(QPixmap("/home/benjamin/Bureau/Projet/GolfMath/Qt_Test_Graphique/testoc/v2/j1.png"));
        lay->addWidget(player1, 13, 11);
        secondeFenetre.setLayout(lay);

    fenetre.setLayout(fenPrinc);

    QWidget::connect(jouer, SIGNAL(clicked()), &secondeFenetre, SLOT(exec()));
    QWidget::connect(quitter, SIGNAL(clicked()), qApp, SLOT(quit()));
    fenetre.show();

    return app.exec();
}
