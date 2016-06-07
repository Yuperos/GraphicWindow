#-------------------------------------------------
#
# Project created by QtCreator 2016-06-03T10:21:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
TARGET = GraphicWindow
TEMPLATE = app

win:{
QMAKE_CXXFLAGS += -std=c++11 -opengl
QMAKE_LFLAGS   += -std=c++11 -opengl
}
unix: !macx {
QMAKE_CXXFLAGS += -std=c++11 -opengl -std=gnu++11
}

SOURCES += main.cpp\
        graphicwindow.cpp \
    traindraw.cpp

HEADERS  += graphicwindow.h \
    traindraw.h

FORMS    += graphicwindow.ui
