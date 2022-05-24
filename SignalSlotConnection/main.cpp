#include <QCoreApplication>
#include "test.h"

void notifications()
{
    Test mom;
    Test child;

    mom.setObjectName("Mom");
    child.setObjectName("Child");

    qDebug() << &mom;
    qDebug() << &child;

    // You have to connect two objects
    // Can have connection type
    QObject::connect(&mom, &Test::alarm, &child, &Test::wake);

    mom.testing();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    notifications();

    return a.exec();
}
