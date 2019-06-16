#include <iostream>>
#include <list>
#include <map>
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
