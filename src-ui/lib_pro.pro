#-------------------------------------------------
#
# Project created by QtCreator 2018-05-27T16:35:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lib_pro
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


SOURCES += \
    Book.cpp \
    Console.cpp \
    Functions.cpp \
    History.cpp \
    Library_manager.cpp \
    Library_reader.cpp \
    Library.cpp \
    Menu_manager.cpp \
    Menu_reader.cpp \
    Menu.cpp \
    Reader.cpp \
    lib_mw.cpp \
    main.cpp \
    userbar.cpp \
    usrmpage.cpp \
    managerpage.cpp \
    addrdialog.cpp \
    libmpage.cpp \
    addbdialog.cpp \
    addnbdialog.cpp \
    qtablemodel.cpp \
    opbtndelegate.cpp \
    brmpage.cpp \
    editinfodialog.cpp \
    bookdetail.cpp \
    librarypage.cpp \
    userpage.cpp

HEADERS += \
    Book.h \
    Console.h \
    Functions.h \
    History.h \
    Library.h \
    Menu.h \
    Reader.h \
    lib_mw.h \
    userbar.h \
    usrmpage.h \
    managerpage.h \
    addrdialog.h \
    libmpage.h \
    addbdialog.h \
    addnbdialog.h \
    qtablemodel.h \
    opbtndelegate.h \
    brmpage.h \
    editinfodialog.h \
    bookdetail.h \
    librarypage.h \
    userpage.h

FORMS += \
    lib_mw.ui \
    userbar.ui \
    usrmpage.ui \
    managerpage.ui \
    addrdialog.ui \
    libmpage.ui \
    addbdialog.ui \
    addnbdialog.ui \
    brmpage.ui \
    editinfodialog.ui \
    bookdetail.ui \
    librarypage.ui \
    userpage.ui

RESOURCES += \
    lib_rs.qrc

INCLUDEPATH += $$PWD
