/* Copyright 2014-2015 Pelagicore Group */
#ifndef DEVINFO_H
#define DEVINFO_H

#include <QQuickItem>
#include <QNetworkInterface>


class DevInfo : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QStringList ipAddresses READ ipAddresses NOTIFY ipAddressesChanged)
    Q_PROPERTY(QStringList ip6Addresses READ ip6Addresses NOTIFY ip6AddressesChanged)
    Q_PROPERTY(QString softwareVersion READ softwareVersion CONSTANT)
    Q_PROPERTY(QString buildId READ buildId CONSTANT)
    Q_PROPERTY(QString nameServer READ nameServer NOTIFY nameServerChanged)
    Q_PROPERTY(QString defaultGateway READ defaultGateway NOTIFY defaultGatewayChanged)

public:
    QStringList ipAddresses();
    QStringList ip6Addresses();
    QString softwareVersion();
    QString buildId();
    QString nameServer();
    QString defaultGateway();

    DevInfo(QObject *parent = 0);
    ~DevInfo();

signals:
    void ipAddressesChanged(QStringList &addresses);
    void ip6AddressesChanged(QStringList &addresses);
    void nameServerChanged(QString &nameServer);
    void defaultGatewayChanged(QString &gateway);

private:
    QStringList getIpAddresses(QAbstractSocket::NetworkLayerProtocol protocol);

};

#endif // DEVINFO_H

