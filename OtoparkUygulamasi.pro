#-------------------------------------------------
#
# Project created by QtCreator 2018-04-28T13:36:48
#
#-------------------------------------------------
QT       += sql
QT       += core gui
QT       += printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OtoparkUygulamasi
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
        main.cpp \
        FrontEnd/ulgnpnlformu.cpp \
        FrontEnd/dbconnection.cpp \
    FrontEnd/yeni_arac_giris.cpp \
    otoparku.cpp \
    FrontEnd/konum.cpp \
    FrontEnd/abone_islem.cpp \
    FrontEnd/arac_cikis_islemleri.cpp \
    FrontEnd/abouthak.cpp


HEADERS += \
        FrontEnd/ulgnpnlformu.h \
        FrontEnd/dbconnection.h \
    FrontEnd/yeni_arac_giris.h \
    otoparku.h \
    FrontEnd/konum.h \
    FrontEnd/abone_islem.h \
    FrontEnd/arac_cikis_islemleri.h \
    FrontEnd/abouthak.h

FORMS += \
        FrontEnd/ulgnpnlformu.ui \
    FrontEnd/yeni_arac_giris.ui \
    otoparku.ui \
    FrontEnd/konum.ui \
    FrontEnd/abone_islem.ui \
    FrontEnd/arac_cikis_islemleri.ui \
    FrontEnd/abouthak.ui



RESOURCES += \
    simgeler/simgeler.qrc

DISTFILES +=
