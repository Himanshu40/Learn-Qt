#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

//    connect(ui->horizontalSlider, &QSlider::valueChanged, ui->progressBar, &QProgressBar::setValue);
    // Here "this" is ui->progressBar
//    connect(ui->horizontalSlider, &QSlider::valueChanged, this, &Widget::respond);

    // Using lambdas
    connect(ui->horizontalSlider, &QSlider::valueChanged, this, [=]() {
        ui->progressBar->setValue(ui->horizontalSlider->value());
        respond(ui->horizontalSlider->value());
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::respond(int value)
{
    qDebug() << "value: " << value;
}

