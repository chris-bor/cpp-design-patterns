TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG += qt

SOURCES += \
    src/main.cpp

HEADERS += \
    src/factory/abstractfactory.h \
    src/factory/figure.h \
    src/factory/scaleablefactory.h \
    src/prototype/prototype.h
