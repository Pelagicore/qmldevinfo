#include "plugin.h"
#include "devinfo.h"

#include <qqml.h>

void QmlDevInfoPlugin::registerTypes(const char *uri)
{
    // @uri com.pelagicore.qmldevinfo
    qmlRegisterType<DevInfo>(uri, 0, 1, "DevInfo");
}


