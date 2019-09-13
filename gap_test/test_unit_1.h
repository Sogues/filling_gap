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
    static int32_t d;
};
int32_t B::d = 10;

#define offset(t, p) (size_t) & (((t*)0)->p)

void test1()
{
    // std::cout << offset(A, a) << std::endl;
    // std::cout << offset(A, b) << std::endl;
    // std::cout << offset(A, c) << std::endl;
    // std::cout << offset(A, size) << std::endl;
    std::cout << sizeof(B) << std::endl;
    B b;
    b.d = 11;
    std::cout << b.d << std::endl;
    B c;
    std::cout << c.d << std::endl;
}
void test2()
{
    bool a = 1 << 10;
    std::cout << (int32_t)a << std::endl;
}
void test3()
{
    int32_t a = -1, b = 1;
    // -1 0
    std::cout << (-1 >> 31) << " " << (b >> 31) << std::endl;
}
void Test()
{
    test3();
}
}  // namespace test_unit_1