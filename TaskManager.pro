TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

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
    dataIO.cpp

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
    dataIO.h

