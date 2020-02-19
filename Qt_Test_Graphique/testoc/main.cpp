#include <QApplication>
#include <QApplicationStateChangeEvent>
#include <QPushButton>
#include <string.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);


    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            QString text = QString(i+j);
            QPushButton b(text);
            b.show();
        }
    }


    return app.exec();
}
