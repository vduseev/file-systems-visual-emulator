#-------------------------------------------------
#
# Project created by QtCreator 2014-02-02T00:35:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FileSystems
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    renderarea.cpp \
    filesystem.cpp \
    ext3.cpp

HEADERS  += mainwindow.h \
    renderarea.h \
    filesystem.h \
    ext3.h

FORMS    += mainwindow.ui
