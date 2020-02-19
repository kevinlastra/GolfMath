#ifndef MAFENETRE_H
#define MAFENETRE_H

#include <QMainWindow>
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include <QInputDialog>
#include <QFileDialog>

class MaFenetre : public QWidget
{
    Q_OBJECT

public:
    MaFenetre(int, int);

public slots:
    void ouvrirDialogue();

private:
    QPushButton *m_boutonDialogue;
};

#endif // MAFENETRE_H
