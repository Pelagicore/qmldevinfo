#ifndef DEVINFO_H
#define DEVINFO_H

#include <QQuickItem>

class DevInfo : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString ipAddress READ ipAddress)
    Q_PROPERTY(QString ipAddress6 READ ipAddress6)

public:
    QString ipAddress();
    QString ipAddress6();

    DevInfo(QObject *parent = 0);
    ~DevInfo();

private:
    QList<QString> getIpAddresses();

};

#endif // DEVINFO_H

