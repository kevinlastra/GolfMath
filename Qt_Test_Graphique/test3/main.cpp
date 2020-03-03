#include <QApplication>
#include "gamemaster.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    gameMaster *gm = new gameMaster;
    gm->show();

    return app.exec();
}
