#-------------------------------------------------
#
# Project created by QtCreator 2016-03-05T13:22:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = plot
TEMPLATE = app
qtHaveModule(printsupport): QT += printsupport

SOURCES += main.cpp\
        widget.cpp \
    graph/qcustomplot.cpp \
    graph.cpp \
    crtbox.cpp \
    dialog.cpp

HEADERS  += widget.h \
    graph/qcustomplot.h \
    graph.h \
    crtbox.h \
    dialog.h

FORMS    += widget.ui \
    graph.ui \
    crtbox.ui \
    dialog.ui
