#ifndef NIVEAUX_H
#define NIVEAUX_H

#include <QObject>
#include <QWidget>
#include <QBoxLayout>
#include <QPushButton>
#include "toutenun.h"

class Niveaux : public QWidget
{
    Q_OBJECT

public:
    Niveaux();

public slots:
    void niveau1();
    void niveau2();
    void niveau3();
    void niveau4();
    void niveau5();
    void niveau6();
    void niveau7();
    void niveau8();
    void niveau9();
    void niveau10();
    void niveau11();
    void niveau12();
    void niveau13();
    void niveau14();
    void niveau15();
    void niveau16();
    void niveau17();
    void niveau18();


private:
    QGridLayout *menu;

    QPushButton *niv1;
    QPushButton *niv2;
    QPushButton *niv3;
    QPushButton *niv4;
    QPushButton *niv5;
    QPushButton *niv6;
    QPushButton *niv7;
    QPushButton *niv8;
    QPushButton *niv9;
    QPushButton *niv10;
    QPushButton *niv11;
    QPushButton *niv12;
    QPushButton *niv13;
    QPushButton *niv14;
    QPushButton *niv15;
    QPushButton *niv16;
    QPushButton *niv17;
    QPushButton *niv18;
};

#endif // NIVEAUX_H
