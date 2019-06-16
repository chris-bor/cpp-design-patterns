#pragma once

#include <QtTest>
#include "tst_cpp_deliberates.h"

class CppDeliberates : public QObject
{
    Q_OBJECT

public:
    CppDeliberates(){}
    ~CppDeliberates(){}

private slots:
    void initTestCase(){}
    void cleanupTestCase(){}
    void test_vector_memset();
    void test_list_memset();
};
