QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle
CONFIG += c++17

TEMPLATE = app

SOURCES +=  \
    tests/main.cpp \
    tests/tst_cpp_deliberates.cpp \
    tests/tst_designpatterns.cpp \
    tests/tst_modern_cpp.cpp

HEADERS += \
    tests/tst_cpp_deliberates.h \
    tests/tst_designpatterns.h \
    tests/tst_modern_cpp.h
