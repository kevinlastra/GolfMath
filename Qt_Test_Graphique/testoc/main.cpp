#include <QApplication>
#include <QApplicationStateChangeEvent>
#include <QPushButton>
#include "mafenetre.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MaFenetre fenetre(500, 250);

    fenetre.show();

    return app.exec();
}
