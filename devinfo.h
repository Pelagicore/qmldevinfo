#ifndef DEVINFO_H
#define DEVINFO_H

#include <QQuickItem>

/*
 * This is a pseudo singleton.
 * It's singleton in terms of "one instance per QQuickView instance"
 * So if you start multiple intances of QQuickView,
 * you'll get multiple instances of this class as well!"
 */

class DevInfo : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString ipAddress READ getIpAddress)

public:
    static inline QObject* getInstance_fromQmlEngine(QQmlEngine *engine, QJSEngine *scriptEngine);

    Q_INVOKABLE QString getIpAddress() { return mIpAddress; }

private:
    DevInfo(QQmlEngine *engine, QObject *parent = 0);
    ~DevInfo();

    void getIpAddresses();
    QString mIpAddress;
    QQmlEngine* mEngine;

    static DevInfo* mInstance;
};

QObject* DevInfo::getInstance_fromQmlEngine(QQmlEngine *engine, QJSEngine *)
{
    if(mInstance == 0)
        mInstance = new DevInfo(engine);

    return mInstance;
}

#endif // DEVINFO_H

