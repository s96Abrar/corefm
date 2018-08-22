#-------------------------------------------------
#
# Project created by QtCreator 2018-08-20T09:12:54
#
#-------------------------------------------------

QT       += core gui widgets  multimedia multimediawidgets  dbus

TARGET = corefm
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++11
CONFIG += silent warn_on

# library for theme
unix:!macx: LIBS += /usr/lib/libcprime.a

FORMS += \
    corefm.ui \
    propertiesw.ui \
    renamedialog.ui

HEADERS += \
    applicationdialog.h \
    corefm.h \
    desktopfile.h \
    fileutils.h \
    mimeutils.h \
    mymodel.h \
    mymodelitem.h \
    progressdlg.h \
    properties.h \
    propertiesw.h \
    renamedialog.h \
    tabbar.h \
    udisks2.h

SOURCES += \
    applicationdialog.cpp \
    corefm.cpp \
    desktopfile.cpp \
    fileutils.cpp \
    main.cpp \
    mimeutils.cpp \
    mymodel.cpp \
    mymodelitem.cpp \
    progressdlg.cpp \
    properties.cpp \
    propertiesw.cpp \
    renamedialog.cpp \
    tabbar.cpp \
    udisks2.cpp

RESOURCES += \
    icons.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

