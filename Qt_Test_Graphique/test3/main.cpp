#include <QApplication>
#include "toutenun.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    ToutEnUn fen;
    fen.show();

    return app.exec();
}
