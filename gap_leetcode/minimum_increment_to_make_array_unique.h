#pragma once
#include <algorithm>
#include <iostream>
#include <vector>

namespace Minimum_Increment_To_Make_Array_Unique
{
//  945.使数组唯一的最小增量
//  945.Minimum Increment to Make Array Unique
//  https://leetcode-cn.com/problems/minimum-increment-to-make-array-unique/
using std::vector;
class Solution
{
  public:
    int minIncrementForUnique(vector<int>& A)
    {
        // int32_t a[100000] = {0};
        // for (const auto& item : A)
        //{
        //    ++a[item];
        //}
        // int32_t cnt = 0;
        // for (int32_t idx = 0; idx < 100000; ++idx)
        //{
        //    if (a[idx] > 1)
        //    {
        //        cnt += a[idx] - 1;
        //        a[idx + 1] += a[idx] - 1;
        //        a[idx] = 1;
        //    }
        //}
        // return cnt;
        std::sort(A.begin(), A.end());
        int32_t step = 0, out = 0;
        for (const auto& item : A)
        {
            if (item < step)
            {
                out += step - item;
                ++step;
            }
            else
            {
                step = item + 1;
            }
        }
        return out;
    }
    static void Test()
    {
        std::cout << "=============" << std::endl;
        {
            Solution solution;
            vector<int> a = {1, 2, 2};
            std::cout << solution.minIncrementForUnique(a) << std::endl;
        }
        std::cout << "=============" << std::endl;
        {
            Solution solution;
            vector<int> a = {3, 2, 1, 2, 1, 7};
            std::cout << solution.minIncrementForUnique(a) << std::endl;
        }
        std::cout << "=============" << std::endl;
    }
};
}  // namespace Minimum_Increment_To_Make_Array_Unique