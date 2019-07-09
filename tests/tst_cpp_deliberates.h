#pragma once

#include <iostream>
#include <QtTest>

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
    void test_weak_ptrs();
};

namespace weakpointer {
struct B;

struct A {
    void set(std::weak_ptr<B> b) {mB = b;}
    void use();
    const std::string mName{"struct A"};
    std::weak_ptr<B> mB;
};

struct B {
    void set(std::weak_ptr<A> a) {mA = a;}
    void use();
    const std::string mName{"struct B"};
    std::weak_ptr<A> mA;
};

} // namespace weakpointer
