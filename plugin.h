/* Copyright 2014-2015 Pelagicore Group */
    #ifndef QMLDEVINFO_PLUGIN_H
#define QMLDEVINFO_PLUGIN_H

#include <QQmlExtensionPlugin>

class QmlDevInfoPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

public:
    void registerTypes(const char *uri);
};

#endif // QMLDEVINFO_PLUGIN_H

