#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QBoxLayout>

#include "toutenun.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

public slots:
    void lancer();

private:
    QVBoxLayout *bouton;
    QPushButton *jouer;
    QPushButton *quitter;
};

#endif // MAINWINDOW_H
