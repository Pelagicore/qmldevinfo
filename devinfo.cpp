/* Copyright 2014-2015 Pelagicore Group */
#include "devinfo.h"

#include <QGuiApplication>
#include <QSettings>


DevInfo::DevInfo(QObject *parent):
    QObject(parent)
{
}

DevInfo::~DevInfo()
{
}


QStringList DevInfo::ipAddresses()
{
    return getIpAddresses(QAbstractSocket::IPv4Protocol);
}

QStringList DevInfo::ip6Addresses()
{
    return getIpAddresses(QAbstractSocket::IPv6Protocol);
}

QString DevInfo::softwareVersion()
{
    QSettings osRelease("/etc/os-release", QSettings::IniFormat);
    return osRelease.value("PRETTY_NAME").toString();
}

QString DevInfo::buildId()
{
    QSettings osRelease("/etc/os-release", QSettings::IniFormat);
    return osRelease.value("BUILD_ID").toString();
}

QString DevInfo::nameServer()
{
    QString ip;

    QFile f("/etc/resolv.conf");
    f.open(QIODevice::ReadOnly);

    while (!f.atEnd()) {
        QString line = QString(f.readLine()).trimmed();
        if(line.startsWith("nameserver ")) {
            ip = line.mid(11, line.length());
            break;
        }
    }

    f.close();

    return ip;
}

QString DevInfo::defaultGateway()
{
    char* gateway = NULL;
    const char* cmd = "netstat -rn | grep '^0.0.0.0' | grep 'UG[ \t]' | awk '{print $2}'";
    FILE* fp = popen(cmd, "r");
    char line[256] = {0x0};

    if(fgets(line, sizeof(line), fp) != NULL)
        gateway = line;

    pclose(fp);

    return QString(gateway);
}

QStringList DevInfo::getIpAddresses(QAbstractSocket::NetworkLayerProtocol protocol)
{
    QStringList addresses;
    QList<QHostAddress> list = QNetworkInterface::allAddresses();

    for (int i = 0; i < list.size(); ++i) {
        QHostAddress address = list.at(i);

        if(address.protocol() == protocol) {
            addresses.append(address.toString());
        }
    }

    return addresses;
}
