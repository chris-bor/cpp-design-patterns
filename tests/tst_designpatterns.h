#pragma once

#include <QtTest>

class DesignPatterns : public QObject
{
    Q_OBJECT

public:
    DesignPatterns();
    ~DesignPatterns();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_factory();
    void test_scaleableFactory();
    void test_abstractFactory();
    void test_prototype();
    void test_singleton();
    void test_cyclicVisitor();
};
