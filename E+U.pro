QT       += core gui sql multimedia charts  printsupport serialport \
    quick
CONFIG += console
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/widgets/shapedclock
INSTALLS += target
SOURCES += \
    AutoResize.cpp \
    Capt_Pression.cpp \
    Employe.cpp \
    capteur_humidite.cpp \
    capteur_mouvement.cpp \
    citoyen.cpp \
    clock.cpp \
    compte.cpp \
    connection.cpp \
    evenement.cpp \
    main.cpp \
    mainwindow.cpp \
    marchand.cpp \
    mission.cpp \
    ramassage.cpp \
    reclamation.cpp \
    ressourcemateriel.cpp \
    smtp.cpp \
    zone_verte.cpp

HEADERS += \
    AutoResize.h \
    Capt_Pression.h \
    Employe.h \
    capteur_humidite.h \
    capteur_mouvement.h \
    citoyen.h \
    clock.h \
    compte.h \
    connection.h \
    dialog.h \
    evenement.h \
    mainwindow.h \
    marchand.h \
    mission.h \
    ramassage.h \
    reclamation.h \
    ressourcemateriel.h \
    smtp.h \
    zone_verte.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    employe_ar_TN.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=\
buttons.qrc

RC_ICONS = munifacility_cm9_3.ico
