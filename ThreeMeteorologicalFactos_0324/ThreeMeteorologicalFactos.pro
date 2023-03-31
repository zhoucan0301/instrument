QT       += core gui serialport network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

#键盘需要添加
static {
    QT += svg
    QTPLUGIN += qtvirtualkeyboardplugin
}

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    axistag.cpp \
    instrumentsetting.cpp \
    keyboard.cpp \
    main.cpp \
    mainwindow.cpp \
    networksetting.cpp \
    qcustomplot.cpp \
    saveform.cpp \
    userloginform.cpp \
    usersetting.cpp

HEADERS += \
    axistag.h \
    instrumentsetting.h \
    keyboard.h \
    mainwindow.h \
    networksetting.h \
    qcustomplot.h \
    saveform.h \
    userloginform.h \
    usersetting.h

FORMS += \
    instrumentsetting.ui \
    keyboard.ui \
    mainwindow.ui \
    networksetting.ui \
    saveform.ui \
    userloginform.ui \
    usersetting.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image/image.qrc

DISTFILES += \
    image/login.png \
    image/others.png \
    image/userlogin.png \
    image/warning.png \
    usersetting.o
