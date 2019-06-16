#include <list>
#include <map>
#include <memory>
#include <vector>

#include "tst_cpp_deliberates.h"

void CppDeliberates::test_vector_memset()
{
    std::vector<char> v {'a', 'b', 'c'};
    for(const auto& c : v)
        std::cout << c;
    std::cout << std::endl;
    std::memset(&v[0], 0, 3);
    for(const auto& c : v)
        std::cout << c;
    std::cout << std::endl;
}

void CppDeliberates::test_list_memset()
{
    std::list<char> l {'a', 'b', 'c'};
    for(const auto& c : l)
        std::cout << c;
    std::cout << std::endl;
    //    std::memset(&l.front(), 0, 3); // commented because it can destroy sth else
    for(const auto& c : l)
        std::cout << c;
    std::cout << std::endl;
}

namespace weakpointer {
void A::use()  {
    if (mB.expired()) {
        std::cout << "mB expired\n";
        QVERIFY(mB.use_count() == 0);
    }
    else {
        auto ptr = mB.lock();
        std::cout << this->mName << " is using " << ptr->mName << std::endl;
        std::cout << "mB use count: " << mB.use_count() << std::endl;
        QVERIFY(mB.use_count() == 2);
    }
}

void B::use()  {
    if (mA.expired()) {
        std::cout << "mA expired\n";
        QVERIFY(mA.use_count() == 0);
    }
    else {
        auto ptr = mA.lock();
        std::cout << this->mName << " is using " << ptr->mName << std::endl;
        std::cout << "mA use count: " << mA.use_count() << std::endl;
        QVERIFY(mA.use_count() == 2);
    }
}
}
void CppDeliberates::test_weak_ptrs()
{
    using namespace weakpointer;
    std::shared_ptr<A> a(new A);
    a->use();
    QVERIFY(a->mB.use_count() == 0);
    {
        std::shared_ptr<B> b(new B);
        QVERIFY(b->mA.use_count() == 0);
        a->set(b);
        QVERIFY(a->mB.use_count() == 1);
        b->set(a);
        QVERIFY(b->mA.use_count() == 1);
        a->use();
        b->use();
    }
    QVERIFY(a->mB.use_count() == 0);
    a->use();
}
