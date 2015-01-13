#ifndef DEVINFO_H
#define DEVINFO_H

#include <arpa/inet.h>

#include <QQuickItem>

class DevInfo : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QStringList ipAddresses READ ipAddresses CONSTANT)
    Q_PROPERTY(QStringList ip6Addresses READ ip6Addresses CONSTANT)
    Q_PROPERTY(QString softwareVersion READ softwareVersion CONSTANT)
    Q_PROPERTY(QString buildId READ buildId CONSTANT)
    Q_PROPERTY(QString nameServer READ nameServer CONSTANT)
    Q_PROPERTY(QString defaultGateway READ defaultGateway CONSTANT)

public:
    QStringList ipAddresses();
    QStringList ip6Addresses();
    QString softwareVersion();
    QString buildId();
    QString nameServer();
    QString defaultGateway();

    DevInfo(QObject *parent = 0);
    ~DevInfo();

private:
    QStringList getIpAddresses(sa_family_t ip_type);

};

#endif // DEVINFO_H

