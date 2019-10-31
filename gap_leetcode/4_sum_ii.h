#pragma once
#include <iostream>
#include <vector>
#include <map>

namespace Si_Sum_II
{
    //  454. 四数相加 II
    //  454. 4Sum II
    //  https://leetcode-cn.com/problems/4sum-ii/
    using std::vector;
    class Solution
    {
    public:
        int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D)
        {
            uint32_t aLen = A.size();
            uint32_t bLen = B.size();
            uint32_t cLen = C.size();
            uint32_t dLen = D.size();
            int out = 0;
            std::map<int32_t, int32_t> absum;
            for (auto &a : A)
            {
                for (auto &b : B)
                {
                    absum[a + b]++;
                }
            }
            std::map<int32_t, int32_t> cdsum;
            for (auto& c : C)
            {
                for (auto &d : D)
                {
                    int32_t val = -c - d;
                    if (absum.count(val))
                    {
                        out += absum[val];
                    }
                }
            }
            return out;
        }
        static void Test()
        {
        }
    };
}  // namespace Si_Sum_II