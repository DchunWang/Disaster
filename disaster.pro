#-------------------------------------------------
#
# Project created by QtCreator 2016-04-21T09:35:07
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = disaster
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    login.cpp \
#    database/testdb.cpp \
#    database/testshowdata.cpp

HEADERS  += widget.h \
    login.h \
#    database/testdb.h \
#    database/testshowdata.h

DISTFILES +=

RESOURCES += \
    skin/src.qrc
