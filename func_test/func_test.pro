QT += testlib
QT -= gui
QT += sql
QT += network
QT += core
CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  \
    ../main.cpp \
    ../function.cpp \
    ../mytcpserver.cpp \
    ../singleton.cpp \
    testmyclass.cpp

HEADERS += \
    testmyclass.h \
    ../function.h \
    ../mytcpserver.h \
    ../singleton.h
