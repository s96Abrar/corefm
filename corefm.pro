#-------------------------------------------------
#
# Project created by QtCreator 2018-08-20T09:12:54
#
#-------------------------------------------------

QT       += core gui widgets multimedia multimediawidgets dbus

TARGET = corefm
TEMPLATE = app

# library for theme and drive mount
unix:!macx: LIBS += -L/usr/lib -lcprime
unix:!macx: LIBS += -L/usr/lib -lcsys

FORMS += \
    corefm.ui \
    propertiesw.ui \
    renamedialog.ui

HEADERS += \
    corefm.h \
    fileutils.h \
    mymodel.h \
    mymodelitem.h \
    progressdlg.h \
    propertiesw.h \
    renamedialog.h \
    tabbar.h \

SOURCES += \
    corefm.cpp \
    fileutils.cpp \
    main.cpp \
    mymodel.cpp \
    mymodelitem.cpp \
    progressdlg.cpp \
    propertiesw.cpp \
    renamedialog.cpp \
    tabbar.cpp \

RESOURCES += \
    icons.qrc

# Disable warnings, enable threading support and c++11
CONFIG += thread silent build_all c++11

# Disable Debug on Release
# CONFIG(release):DEFINES += QT_NO_DEBUG_OUTPUT

# Build location

BUILD_PREFIX = $$(CA_BUILD_DIR)

isEmpty( BUILD_PREFIX ) {
        BUILD_PREFIX = ./build
}

MOC_DIR       = $$BUILD_PREFIX/moc-qt5
OBJECTS_DIR   = $$BUILD_PREFIX/obj-qt5
RCC_DIR	      = $$BUILD_PREFIX/qrc-qt5
UI_DIR        = $$BUILD_PREFIX/uic-qt5


unix {
        isEmpty(PREFIX) {
                PREFIX = /usr
        }
        BINDIR = $$PREFIX/bin

        target.path = $$BINDIR

        desktop.path = $$PREFIX/share/applications/
        desktop.files = "corefm.desktop"

        icons.path = $$PREFIX/share/coreapps/icons/
        icons.files = icons/corefm.svg

        INSTALLS += target icons desktop
}

DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += "HAVE_POSIX_OPENPT"
