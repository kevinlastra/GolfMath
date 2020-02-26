#include <QApplication>
#include "fenprinc.h"

int main(int argc, char* argv[]){

    QApplication app(argc, argv);

    FenPrinc fenetre;
    fenetre.show();

    return app.exec();
}
