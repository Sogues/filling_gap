#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "util.h"

namespace Longest_Increasing_Subsequence
{
using std::vector;
//  300. 最长上升子序列
//  300. Longest Increasing Subsequence
//  https://leetcode-cn.com/problems/longest-increasing-subsequence/
class Solution
{
  public:
    int lengthOfLIS(vector<int>& nums)
    {
        int n = nums.size();
        std::vector<int> dp(n, 1);
        int out = 0;
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
            out = std::max(out, dp[i]);
        }
        return out;
    }
    static void Test()
    {
        {
            std::vector<int> nums = util::Split(util::Trim(util::Trim("[10,9,2,5,3,7,101,18]", '['), ']'), ",");
            Solution solution;
            auto out = solution.lengthOfLIS(nums);
            std::cout << "=============" << std::endl;
            std::cout << out << std::endl;
            std::cout << "=============" << std::endl;
        }
    }
};
}  // namespace Longest_Increasing_Subsequence