#include "widget.h"
#include "./ui_widget.h"
#include <QDebug>
#include <QMouseEvent>
#include <QMenu>
#include <QWheelEvent>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "Mouse pressed" << event->pos();
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug() << "Mouse released" << event->pos();
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    qDebug() << "Mouse moved" << event->pos();
}

void Widget::closeEvent(QCloseEvent *event)
{
    qDebug() << "Widget closed";
    event->accept();
    //    event->ignore();
}

void Widget::contextMenuEvent(QContextMenuEvent *event)
{
    qDebug() << "Context menu";

    QMenu *menu {new QMenu(this)};

    menu->addAction(tr("File"));
    menu->addAction(tr("View"));

    // In relation to background not the actual window of qt
//    menu->popup(event->pos());
    // In relation to the actual window of qt
    menu->popup(mapToGlobal(event->pos()));

    // Know postion of Menu through x and y co-ordinates
    qDebug() << "X: " << event->x() << ", Y: " << event->y();

    qDebug() << "Reason: " << event->reason();
}

void Widget::enterEvent(QEnterEvent *event)
{
    qDebug() << "Enter event";
}

void Widget::leaveEvent(QEvent *event)
{
    qDebug() << "Leave event";
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "Key pressed: " << event->key() << ":" << event->text();

    if (event->modifiers() & Qt::ShiftModifier) {
        qDebug() << "Shift + " << event->text();
    }

    if (event->modifiers() & Qt::ControlModifier) {
        qDebug() << "Control + " << event->text();
    }

    if (event->modifiers() & Qt::AltModifier) {
        qDebug() << "Alt + " << event->text();
    }

    if (event->modifiers() & Qt::ControlModifier) {
        if (event->key() == Qt::Key_S) {
            qDebug() << "Ctrl + " << event->text() << " detected";
        }
    }
}

void Widget::wheelEvent(QWheelEvent *event)
{
    qDebug() << "Wheel event delta: " << event->pixelDelta();
    qDebug() << "Orientation: " << event->angleDelta();
}

void Widget::paintEvent(QPaintEvent *event)
{
    qDebug() << "paint event triggered";
}

void Widget::resizeEvent(QResizeEvent *event)
{
    qDebug() << "Widget resized, old size: " << event->oldSize();
    qDebug() << "New size: " << event->size();
}

