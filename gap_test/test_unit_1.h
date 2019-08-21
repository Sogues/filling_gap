#pragma once
#include <iostream>

namespace test_unit_1
{
struct A
{
    int a : 2;
    int b : 3;
    long long int c : 4;
    char size[0];
};

struct B
{
    int a;
    int b;
    long long int c;
    char size[0];
};

#define offset(t, p) (size_t) & (((t*)0)->p)

void test1()
{
    // std::cout << offset(A, a) << std::endl;
    // std::cout << offset(A, b) << std::endl;
    // std::cout << offset(A, c) << std::endl;
    std::cout << offset(A, size) << std::endl;
}
void Test()
{
    test1();
}
}  // namespace test_unit_1