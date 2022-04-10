TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Barbaro.cpp \
        CombatEvent.cpp \
        Mago.cpp \
        Personaje.cpp \
        Skill.cpp \
        WaifuJRPG.cpp \
        funciones.cpp \
        main.cpp

HEADERS += \
    Barbaro.h \
    CombatEvent.h \
    Mago.h \
    Personaje.h \
    Skill.h \
    WaifuJRPG.h \
    funciones.h \
    mini/ini.h
