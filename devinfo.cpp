#include "devinfo.h"

#include <QGuiApplication>
#include <QSettings>

#include <stdio.h>
#include <sys/types.h>
#include <ifaddrs.h>
#include <netinet/in.h>
#include <string.h>

DevInfo::DevInfo(QObject *parent):
    QObject(parent)
{
}

DevInfo::~DevInfo()
{
}


QStringList DevInfo::ipAddresses()
{
    return getIpAddresses(AF_INET);
}

QStringList DevInfo::ip6Addresses()
{
    return getIpAddresses(AF_INET6);
}

QString DevInfo::softwareVersion()
{
    QSettings osRelease("/etc/os-release", QSettings::IniFormat);

    QString prettyName = osRelease.value("PRETTY_NAME").toString();
    QString buildNumber = " (" + osRelease.value("BUILD_ID", "snapshot").toString() + ")";

    return prettyName + buildNumber;
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
    const char* cmd = "netstat -rn | grep '^0.0.0.0' | grep 'UG[ \t]' |  awk '{print $2}'";
    FILE* fp = popen(cmd, "r");
    char line[256] = {0x0};

    if(fgets(line, sizeof(line), fp) != NULL)
        gateway = line;

    pclose(fp);

    return QString(gateway);
}

QStringList DevInfo::getIpAddresses(sa_family_t ip_type)
{
    QStringList addresses;

    struct ifaddrs * ifAddrStruct = NULL;
    struct ifaddrs * ifa = NULL;
    void * tmpAddrPtr = NULL;

    getifaddrs(&ifAddrStruct);

    for (ifa = ifAddrStruct; ifa != NULL; ifa = ifa->ifa_next) {

        if (!ifa->ifa_addr) {
            continue;
        }

        if (ip_type == AF_INET && ifa->ifa_addr->sa_family == AF_INET) { // check it is IP4

            // is a valid IP4 Address
            tmpAddrPtr=&((struct sockaddr_in *)ifa->ifa_addr)->sin_addr;
            char addressBuffer[INET_ADDRSTRLEN];
            inet_ntop(AF_INET, tmpAddrPtr, addressBuffer, INET_ADDRSTRLEN);
            addresses.append(QString(addressBuffer));

        } else if (ip_type == AF_INET6 && ifa->ifa_addr->sa_family == AF_INET6) { // check it is IP6

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
