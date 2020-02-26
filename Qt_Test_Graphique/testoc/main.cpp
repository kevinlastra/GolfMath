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

    QMainWindow fenetre;
        QPushButton *button = new QPushButton("Play", &fenetre);
        button->move(25, 20);

    QDialog secondeFenetre(&fenetre);
        QGridLayout *lay = new QGridLayout;
        lay->setSpacing(0);
        for (int i = 0; i <= 10; i++){
            for (int j = 0; j <= 30; j++){
                if (i == 0 or j == 0 or i == 10 or j == 30){
                    QLabel *image = new QLabel();
                    image->setPixmap(QPixmap("/home/benjamin/Bureau/Projet/GolfMath/Qt_Test_Graphique/testoc/water.bmp"));
                    lay->addWidget(image, i, j);
                }
                else if ((i >= 4 && i <= 6) && (j >= 4 && j <= 6)){
                    QLabel *image = new QLabel();
                    image->setPixmap(QPixmap("/home/benjamin/Bureau/Projet/GolfMath/Qt_Test_Graphique/testoc/start_1.jpg"));
                    lay->addWidget(image, i, j);
                }
                else if (i == 5 && j == 25){
                    QLabel *image = new QLabel();
                    image->setPixmap(QPixmap("/home/benjamin/Bureau/Projet/GolfMath/Qt_Test_Graphique/testoc/hole.bmp"));
                    lay->addWidget(image, i, j);
                }
                else if ((i == 1 && j >= 10 && j <= 20) || (i == 2 && j >= 12 && j <= 18) || (i == 3 && j >= 14 && j <= 16) ||
                         (i == 9 && j >= 10 && j <= 20) || (i == 8 && j >= 12 && j <= 18) || (i == 7 && j >= 14 && j <= 16)){
                    QLabel *image = new QLabel();
                    image->setPixmap(QPixmap("/home/benjamin/Bureau/Projet/GolfMath/Qt_Test_Graphique/testoc/sand_pressed_1.jpg"));
                    lay->addWidget(image, i, j);
                }
                else {
                    QLabel *image = new QLabel();
                    image->setPixmap(QPixmap("/home/benjamin/Bureau/Projet/GolfMath/Qt_Test_Graphique/testoc/green_pressed_1.jpg"));
                    lay->addWidget(image, i, j);
                }
            }
        }
        secondeFenetre.setLayout(lay);

    QWidget::connect(button, SIGNAL(clicked()), &secondeFenetre, SLOT(exec()));
    fenetre.show();

    return app.exec();
}
