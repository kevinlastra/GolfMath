#include "fencodegen.h"

FenCodeGen::FenCodeGen(QString &code, QWidget *parent) : QDialog(parent){
    codeGenerer = new QTextEdit;
    codeGenerer->setPlainText(code);
    codeGenerer->setReadOnly(true);
    codeGenerer->setFont(QFont("Courrier"));
    codeGenerer->setLineWrapMode(QTextEdit::NoWrap);

    fermer = new QPushButton("Fermer");

    QVBoxLayout *layoutPrincipal = new QVBoxLayout;
    layoutPrincipal->addWidget(codeGenerer);
    layoutPrincipal->addWidget(fermer);

    resize(350, 450);
    setLayout(layoutPrincipal);

    connect(fermer, SIGNAL(clicked()), this, SLOT(accept()));
}
