TEMPLATE = app TARGET = name_of_the_app

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS += \
    dialog.h

SOURCES += \
    dialog.cpp \
    main.cpp