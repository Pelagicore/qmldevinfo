TEMPLATE = lib
TARGET = qmldevinfo
QT += qml quick
CONFIG += qt plugin

TARGET = $$qtLibraryTarget($$TARGET)
uri = com.pelagicore.DevInfo

dest = $$OUT_PWD/imports/$$replace(uri, \., /)
DESTDIR = $$replace(dest, /, $$QMAKE_DIR_SEP)

isEmpty(version) {
    version = 1.0
}

# Input
SOURCES += \
    devinfo.cpp \
    plugin.cpp

HEADERS += \
    devinfo.h \
    plugin.h

OTHER_FILES = qmldir \
    Main.qml

copy_qmldir.target = $$DESTDIR/qmldir
copy_qmldir.depends = $$_PRO_FILE_PWD_/qmldir
copy_qmldir.commands = $(COPY_FILE) \"$$replace(copy_qmldir.depends, /, $$QMAKE_DIR_SEP)\" \"$$replace(copy_qmldir.target, /, $$QMAKE_DIR_SEP)\"
QMAKE_EXTRA_TARGETS += copy_qmldir
PRE_TARGETDEPS += $$copy_qmldir.target

!equals(_PRO_FILE_PWD_, $$OUT_PWD) {
    copy_qml.target = $$OUT_PWD/Main.qml
    copy_qml.depends = $$_PRO_FILE_PWD_/Main.qml
    copy_qml.commands = $(COPY_FILE) \"$$replace(copy_qml.depends, /, $$QMAKE_DIR_SEP)\" \"$$replace(copy_qml.target, /, $$QMAKE_DIR_SEP)\"
    QMAKE_EXTRA_TARGETS += copy_qml
    PRE_TARGETDEPS += $$copy_qml.target
}

qmldir.files = qmldir
unix {
    installPath = $$[QT_INSTALL_QML]/$$replace(uri, \\., /)
    qmldir.path = $$installPath
    target.path = $$installPath
    INSTALLS += target qmldir
}

