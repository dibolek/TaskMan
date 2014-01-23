QT += core
QT -= gui

TARGET = TaskManager
TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle



INCLUDEPATH += C:\Qt\Qt5.2.0\5.2.0\mingw48_32\include
INCLUDEPATH += C:\Qt\boost_1_55_0

SOURCES += main.cpp \
    allusers.cpp \
    user.cpp \
    event.cpp \
    meeting.cpp \
    todolist.cpp \
    note.cpp \
    calendar.cpp \
    date.cpp \
    functions.cpp \
    datastorage.cpp

HEADERS += \
    allusers.h \
    user.h \
    event.h \
    meeting.h \
    todolist.h \
    note.h \
    calendar.h \
    date.h \
    functions.h \
    datastorage.h

