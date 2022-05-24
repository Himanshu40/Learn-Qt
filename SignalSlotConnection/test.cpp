#include "test.h"

Test::Test(QObject *parent)
    : QObject{parent}
{
    qInfo() << this << " constructed";
}

Test::~Test()
{
    qInfo() << this << " deconstructed";
}

void Test::testing()
{
    QString message {"Wake up"};

    emit alarm(message);
}

void Test::wake(QString message)
{
    qInfo() << "From " << sender() << message;
}
