#ifndef FENPRINC_H
#define FENPRINC_H

#include <QObject>
#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QGroupBox>
#include <QDateEdit>
#include <QPushButton>
#include <QObject>
#include <QFormLayout>
#include <QTextEdit>
#include <QDialog>
#include <QtGui>
#include <QMessageBox>

class FenPrinc : public QWidget
{

    Q_OBJECT

public:
    FenPrinc();

private slots:
    void genererCode();

private:
    QLineEdit *nom;
    QLineEdit *classeMere;
    QCheckBox *protections;
    QCheckBox *genererConstructeur;
    QCheckBox *genererDestructeur;
    QGroupBox *groupeCommentaires;
    QLineEdit *auteur;
    QDateEdit *date;
    QTextEdit *role;
    QPushButton *generer;
    QPushButton *quitter;

};

#endif // FENPRINC_H
