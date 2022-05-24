#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QDebug>

class Test : public QObject
{
    Q_OBJECT
public:
    explicit Test(QObject *parent = nullptr);
    ~Test();

    void testing();

signals:
    // Always public
    // Always defined
    // Never implemented
    void alarm(QString message);

public slots:
    // Can be public, private and protected
    // Always defined and implemented
    // Should match the respective signal
    void wake(QString message);
};

#endif // TEST_H
