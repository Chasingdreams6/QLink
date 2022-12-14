QT       += core gui
QT += testlib
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    endpage.cpp \
    helppage.cpp \
    main.cpp \
    mainwindow.cpp \
    map.cpp \
    matchtest.cpp \
    pausewidget.cpp \
    startpage.cpp \
    user.cpp

HEADERS += \
    constant.h \
    endpage.h \
    helppage.h \
    mainwindow.h \
    map.h \
    matchtest.h \
    pausewidget.h \
    startpage.h \
    user.h \
    vars.h

FORMS += \
    endpage.ui \
    helppage.ui \
    mainwindow.ui \
    pausewidget.ui \
    startpage.ui

TRANSLATIONS += \
    lib_zh_CN.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc

DISTFILES += \
    images/item1_hinted.jpeg \
    images/item2_hinted.jpeg \
    images/item3_hinted.jpeg \
    images/item4_hinted.jpeg \
    images/item5_hinted.jpeg \
    images/item6_hinted.jpeg
