#include "childlineedit.h"
#include <QKeyEvent>

ChildLineEdit::ChildLineEdit(QWidget *parent)
    : ParentLineEdit{parent}
{

}

void ChildLineEdit::keyPressEvent(QKeyEvent *event)
{
//    qDebug() << "ChildLineEdit event called";
//    ParentLineEdit::keyPressEvent(event);

    qDebug() << "ChildLineEdit Accepted" << event->isAccepted();

    if (event->key() == Qt::Key_Delete) {
        qDebug() << "Delete key pressed";
        clear();
    }
    else {
        ParentLineEdit::keyPressEvent(event);
    }
}
