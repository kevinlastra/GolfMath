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

#include "jeu.h"

class nbJ_et_map : public QWidget
{
    Q_OBJECT

public:
    nbJ_et_map();

private slots:
    void lancer();

private:
    QFormLayout *option;
    QLineEdit *nbJoueur;
    QLineEdit *map;
    QPushButton *lancerJeu;
};

#endif // NBJ_ET_MAP_H
