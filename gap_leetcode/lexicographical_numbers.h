#pragma once

#include <iostream>
#include <vector>

namespace Lexicographical_Number
{
//  386.×ÖµäÐòÅÅÊý
//  386.Lexicographical Numbers
//  https://leetcode-cn.com/problems/lexicographical-numbers/
using std::vector;
class Solution
{
  public:
    vector<int> lexicalOrder(int n)
    {
        vector<int> out;
        out.resize(n);
        int32_t next = 0;
        func(out, next, n, 1);
        return out;
    }
    void func(vector<int>& out, int32_t& next, int32_t n, int32_t start)
    {
        if (start > n)
        {
            return;
        }
        for (int32_t idx = 0; idx <= 9; ++idx)
        {
            int32_t tmp = start + idx;
            if (tmp > n || (start == 1 && idx == 9))
            {
                break;
            }
            out[next++] = tmp;
            func(out, next, n, tmp * 10);
        }
    }
    static void Test()
    {
        std::cout << "=============" << std::endl;
        {
            Solution solution;
            for (const auto& item : solution.lexicalOrder(13))
            {
                std::cout << item << ",";
            }
            std::cout << std::endl;
        }
        std::cout << "=============" << std::endl;
        {
            Solution solution;
            for (const auto& item : solution.lexicalOrder(100))
            {
                std::cout << item << ",";
            }
            std::cout << std::endl;
        }
        std::cout << "=============" << std::endl;
        {
            Solution solution;
            for (const auto& item : solution.lexicalOrder(34))
            {
                std::cout << item << ",";
            }
            std::cout << std::endl;
        }
        std::cout << "=============" << std::endl;
    }
};
}  // namespace Lexicographical_Number