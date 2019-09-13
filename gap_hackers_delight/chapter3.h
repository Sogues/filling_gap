#pragma once
#include <iostream>
#include "common.h"

namespace Chapter3
{
class Solution
{
  public:
    static int32_t flp2_1(int32_t val)
    {
        val = val | (val >> 1);
        val = val | (val >> 2);
        val = val | (val >> 4);
        val = val | (val >> 8);
        val = val | (val >> 16);
        return val - (val >> 1);
    }
    static int32_t flp2_2(int32_t val)
    {
        int32_t out = 0;
        do
        {
            out = val;
            val = val & (val - 1);
        } while (val);
        return out;
    }
    static int32_t clp2_1(int32_t val)
    {
        --val;
        val = val | (val >> 1);
        val = val | (val >> 2);
        val = val | (val >> 4);
        val = val | (val >> 8);
        val = val | (val >> 16);
        return val + 1;
    }
    static int32_t clp2_2(int32_t val)
    {
        int32_t out = 1;
        while (out < val)
        {
            out <<= 1;
        }
        return out;
    }
    static void Chapter3_2()
    {
        char* binary = new char[32];
        // int32_t a = 65535;
        // tobin(a, binary);
        // std::cout << binary << std::endl;
        std::cout << "=============" << std::endl;
        {
            // 00000000000000000000000001010010
            // 00000000000000000000000001000000
            // 00000000000000000000000001000000
            // 00000000000000000000000010000000
            int32_t a = 0b001010010;
            tobin(a, binary);
            std::cout << binary << std::endl;
            tobin(flp2_1(a), binary);
            std::cout << binary << std::endl;
            tobin(flp2_2(a), binary);
            std::cout << binary << std::endl;
            tobin(clp2_1(a), binary);
            std::cout << binary << std::endl;
            tobin(clp2_2(a), binary);
            std::cout << binary << std::endl;
        }
        std::cout << "=============" << std::endl;
        {
            // 00000000000000000000000001000000
            // 00000000000000000000000001000000
            // 00000000000000000000000001000000
            // 00000000000000000000000010000000
            int32_t a = 0b001000000;
            tobin(a, binary);
            std::cout << binary << std::endl;
            tobin(flp2_1(a), binary);
            std::cout << binary << std::endl;
            tobin(flp2_2(a), binary);
            std::cout << binary << std::endl;
            tobin(clp2_1(a), binary);
            std::cout << binary << std::endl;
            tobin(clp2_2(a), binary);
            std::cout << binary << std::endl;
        }
        std::cout << "=============" << std::endl;

        delete[] binary;
    }
    static void Chapter3_4()
    {
        char* binary = new char[32];
        std::cout << "=============" << std::endl;
        {
            int32_t a = 0b001000000;
            for (int32_t idx = 0; idx <= 16; ++idx)
            {
                ++a;
                tobin(a, binary);
                std::cout << binary << std::endl;
                tobin((a + 4) & -8, binary);
                std::cout << binary << std::endl;
                std::cout << std::endl;
            }
        }
        std::cout << "=============" << std::endl;
        {
            int32_t a = 0b001000000;
            for (int32_t idx = 0; idx <= 16; ++idx)
            {
                ++a;
                tobin(a, binary);
                std::cout << binary << std::endl;
                tobin((a + 3) & -8, binary);
                std::cout << binary << std::endl;
                std::cout << std::endl;
            }
        }
        std::cout << "=============" << std::endl;
        delete[] binary;
    }
};
}  // namespace Chapter3
