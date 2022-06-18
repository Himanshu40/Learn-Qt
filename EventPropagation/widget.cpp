#include "widget.h"
#include "./ui_widget.h"
#include "childbutton.h"
#include "childlineedit.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ChildButton *button {new ChildButton(this)};
    button->setText("Child Button");
    connect(button, &ChildButton::clicked, [=](){
        qDebug() << "Button clicked";
    });

    ui->verticalLayout->addWidget(button);

    ChildLineEdit *lineEdit {new ChildLineEdit(this)};

    ui->verticalLayout->addWidget(lineEdit);
}

Widget::~Widget()
{
    delete ui;
}

