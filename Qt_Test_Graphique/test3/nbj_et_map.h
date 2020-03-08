#ifndef NBJ_ET_MAP_H
#define NBJ_ET_MAP_H

#include <QApplication>
#include <QWidget>
#include <QDialog>
#include <QFormLayout>
#include <QPushButton>
#include <QBoxLayout>
#include <QLineEdit>
#include <QObject>
#include <QMessageBox>
#include <QSpinBox>

#include "jeu.h"

class nbJ_et_map : public QWidget
{
    Q_OBJECT

public:
    nbJ_et_map();
    QSpinBox *nb;
    QSpinBox *map;

private slots:
    void lancer();

private:
    QFormLayout *option;
    QPushButton *lancerJeu;
};

#endif // NBJ_ET_MAP_H
