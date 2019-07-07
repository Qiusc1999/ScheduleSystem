#-------------------------------------------------
#
# Project created by QtCreator 2019-05-14T18:21:10
#
#-------------------------------------------------

QT       += core gui
RC_FILE = logo.rc
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = loginUI

TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        aboutform.cpp \
        findscheduleform.cpp \
        info_registersucessform.cpp \
        loginsuccessform.cpp \
        main.cpp \
        loginui.cpp \
        mainform.cpp \
        newscheduleform.cpp \
        registerform.cpp \
        scheduleform.cpp \
        showscheduleform.cpp \
        warning_accountNullform.cpp \
        warning_noaccountform.cpp \
        warning_pswderrorform.cpp

HEADERS += \
        aboutform.h \
        class.h \
        findscheduleform.h \
        info_registersucessform.h \
        loginsuccessform.h \
        loginui.h \
        mainform.h \
        newscheduleform.h \
        registerform.h \
        scheduleform.h \
        showscheduleform.h \
        warning_accountNullform.h \
        warning_noaccountform.h \
        warning_pswderrorform.h

FORMS += \
        aboutform.ui \
        findscheduleform.ui \
        info_registersucessform.ui \
        loginsuccessform.ui \
        loginui.ui \
        mainform.ui \
        newscheduleform.ui \
        registerform.ui \
        scheduleform.ui \
        showscheduleform.ui \
        warning_accountNullform.ui \
        warning_noaccountform.ui \
        warning_pswderrorform.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image1.qrc
