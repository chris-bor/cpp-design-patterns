#pragma once

#include <iostream>
#include <list>

#include <QtTest>

class ModernCpp : public QObject
{
    Q_OBJECT

public:
    ModernCpp(){}
    ~ModernCpp(){}

private slots:
    void initTestCase(){}
    void cleanupTestCase(){}
    void test_expressionEvaluationOrder();
    void test_myContainerRangeLoop();
    void test_autoInitialization();
};

namespace  mycontainerrangeloop {
class MyContainer
{
    std::list<int> mValues { 1, 2, 3, 4, 5 };

public:
    friend std::list<int>::iterator begin(MyContainer &container) {
        return container.mValues.begin();
    }
    friend std::list<int>::iterator end(MyContainer &container) {
        return container.mValues.end();
    }
};

} // namespace mycontainerrangeloop
