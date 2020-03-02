#include "keypress.h"
#include <QApplication>
#include <QKeyEvent>

keypress::keypress(QWidget *parent) : QWidget(parent)
{
    myLabel = new QLabel("Label");
    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(myLabel);
    setLayout(mainLayout);
}
