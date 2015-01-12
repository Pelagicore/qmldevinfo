#include "devinfo.h"

#include <QGuiApplication>
#include <stdio.h>
#include <sys/types.h>
#include <ifaddrs.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

DevInfo::DevInfo(QObject *parent):
    QObject(parent)
{

}

DevInfo::~DevInfo()
{
}


QString DevInfo::ipAddress()
{
    QList<QString> addresses = getIpAddresses();
    QStringList ips;

    for(int i = 0; i < addresses.count(); i++) {
        QString address = addresses.at(i);

        if(address != "127.0.0.1" && address.indexOf(":") == -1) {
            ips << address;
        }
    }

    return ips.join(", ");
}

QString DevInfo::ipAddress6()
{
    QList<QString> addresses = getIpAddresses();
    QStringList ips;

    for(int i = 0; i < addresses.count(); i++) {
        QString address = addresses.at(i);

        if(address != "::1" && address.indexOf(".") == -1) {
            ips << address;
        }
    }

    return ips.join(", ");
}

QList<QString> DevInfo::getIpAddresses()
{
    QList<QString> addresses;

    struct ifaddrs * ifAddrStruct=NULL;
    struct ifaddrs * ifa=NULL;
    void * tmpAddrPtr=NULL;

    getifaddrs(&ifAddrStruct);

    for (ifa = ifAddrStruct; ifa != NULL; ifa = ifa->ifa_next) {

        if (!ifa->ifa_addr) {
            continue;
        }

        if (ifa->ifa_addr->sa_family == AF_INET) { // check it is IP4

            // is a valid IP4 Address
            tmpAddrPtr=&((struct sockaddr_in *)ifa->ifa_addr)->sin_addr;
            char addressBuffer[INET_ADDRSTRLEN];
            inet_ntop(AF_INET, tmpAddrPtr, addressBuffer, INET_ADDRSTRLEN);
            addresses.append(QString(addressBuffer));

        } else if (ifa->ifa_addr->sa_family == AF_INET6) { // check it is IP6

            // is a valid IP6 Address
            tmpAddrPtr=&((struct sockaddr_in6 *)ifa->ifa_addr)->sin6_addr;
            char addressBuffer[INET6_ADDRSTRLEN];
            inet_ntop(AF_INET6, tmpAddrPtr, addressBuffer, INET6_ADDRSTRLEN);
            addresses.append(QString(addressBuffer));
        }
    }
    if (ifAddrStruct!=NULL) freeifaddrs(ifAddrStruct);

    return addresses;
}
