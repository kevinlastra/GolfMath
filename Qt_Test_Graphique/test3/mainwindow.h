#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QBoxLayout>

#include "niveaux.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

public slots:
    void lancer();

private:
    QPushButton *jouer;
    QPushButton *quitter;
};

#endif // MAINWINDOW_H
