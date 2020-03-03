#ifndef GAMEMASTER_H
#define GAMEMASTER_H

#include <QApplication>
#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QBoxLayout>
#include <QFormLayout>
#include <QPushButton>

#include "nbj_et_map.h"
#include "jeu.h"

class gameMaster : public QWidget
{
    Q_OBJECT

public:
    gameMaster();

signals:
    void compter();

private slots:
    void lancerOption();

private:
    QVBoxLayout *principal;
    QLabel *titre;
    QPushButton *jouer;
    QPushButton *inutile;
    QPushButton *quitter;

};

#endif // GAMEMASTER_H
