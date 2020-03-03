#ifndef JEU_H
#define JEU_H

#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QBoxLayout>
#include <QDialog>
#include <QObject>

class Jeu : public QWidget
{
    Q_OBJECT

public:
    Jeu();

private:
    QVBoxLayout *layImage;
    QLabel *image;
};

#endif // JEU_H
