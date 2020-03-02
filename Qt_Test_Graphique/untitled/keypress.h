#ifndef KEYPRESS_H
#define KEYPRESS_H

#include <QWidget>
#include <QtGui>
#include <QLabel>
#include <QBoxLayout>


class keypress : public QWidget
{
    Q_OBJECT

public:
    keypress(QWidget *parent = 0);

protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

private:
    QLabel *myLabel;
    QVBoxLayout *mainLayout;
};

#endif // KEYPRESS_H
