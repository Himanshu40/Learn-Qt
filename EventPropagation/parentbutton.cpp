#include "parentbutton.h"
#include <QDebug>

ParentButton::ParentButton(QWidget *parent)
    : QPushButton{parent}
{

}

void ParentButton::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "Parent button mousePressEvent called";
    QPushButton::mousePressEvent(event);
}
