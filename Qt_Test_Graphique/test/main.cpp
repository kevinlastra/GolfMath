#include <QApplication>
#include <QtWidgets/QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QPushButton bouton("Salut !");
    bouton.show();

    return app.exec();
}
