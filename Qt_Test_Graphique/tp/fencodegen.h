#ifndef FENCODEGEN_H
#define FENCODEGEN_H

#include <QObject>
#include <QWidget>
#include <QDialog>
#include <QTextEdit>
#include <QBoxLayout>
#include <QPushButton>

class FenCodeGen : public QDialog
{
public:
    FenCodeGen(QString &code, QWidget *parent);

private:
    QTextEdit *codeGenerer;
    QPushButton *fermer;
};

#endif // FENCODEGEN_H
