/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  17/10/2016 15:41:47 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  kr.borowiec@gmail.com, 
 *        Company:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <type_traits>

using namespace std;


enum class AA : unsigned
{
    X,
    Y,
    Z
};


template<typename T>
auto ToValue(const T& a) -> std::underlying_type_t<T> 
{
    return static_cast<std::underlying_type_t<T>>(a);
}


int main()
{
    unsigned aa = ToValue(AA::X);
    unsigned ab = ToValue(AA::Y);
    //unsigned aa = AA::X;
    cout << aa << endl;
    cout << ab << endl;

    return 0;
}
