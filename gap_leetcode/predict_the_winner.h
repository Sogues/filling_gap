#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

namespace Predict_The_Winner
{
//  486. 预测赢家
//  486. Predict the Winner
//  https://leetcode-cn.com/problems/predict-the-winner/
using std::vector;
class Solution
{
  public:
#ifndef solution_1
    bool PredictTheWinner(vector<int>& nums)
    {
        int32_t length = nums.size();
        if (!(1 & length))
        {
            return true;
        }
        std::vector<std::vector<int>> dp(length, std::vector<int>(length, 0));
        for (size_t i = 0; i < length; i++)
        {
            dp[i][i] = nums[i];
        }
        // 步进
        for (int32_t step = 1; step < length; ++step)
        {
            // 迭代
            for (int32_t i = 0, j = step; j < length; ++i, ++j)
            {
                dp[i][j] = std::max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
            }
        }
        return dp[0][length - 1] >= 0;
    }
#else
    bool PredictTheWinner(vector<int>& nums)
    {
        int32_t length = nums.size();
        if (!(1 & length))
        {
            return true;
        }
        uint32_t sum = 0, a = 0;
        for (auto& elem : nums)
        {
            sum += elem;
        }
        int32_t begin = 0, ebegin = length - 1;
        a = func(nums, begin, ebegin);
        return a >= (sum - a);
    }
    uint32_t func(vector<int>& nums, uint32_t begin, uint32_t ebegin)
    {
        if (begin > ebegin)
        {
            return 0;
        }
        if (begin == ebegin)
        {
            return nums[begin];
        }
        if (begin + 1 == ebegin)
        {
            return std::max(nums[begin], nums[ebegin]);
        }
        return std::max(nums[begin] + std::min(func(nums, begin + 2, ebegin), func(nums, begin + 1, ebegin - 1)),
                        nums[ebegin] + std::min(func(nums, begin + 1, ebegin + 1), func(nums, begin, ebegin - 2)));
    }
#endif
    static void Test()
    {
        auto str2Arr = [](std::string in, std::string dep) -> std::vector<int> {
            in = in.substr(1, in.size() - 2);
            std::vector<int> out;
            std::string::size_type pos1 = 0;
            auto pos2 = in.find(dep, pos1);
            while (std::string::npos != pos2)
            {
                out.push_back(std::atoi(in.substr(pos1, pos2).c_str()));
                pos1 = pos2 + 1;
                pos2 = in.find(dep, pos1);
            }
            out.push_back(std::atoi(in.substr(pos1).c_str()));
            return out;
        };
        {
            std::string test1 = "[1,1,1]";
            std::vector<int> nums = str2Arr(test1, ",");
            Solution solution;
            solution.PredictTheWinner(nums);
        }
    }
};  // namespace Predict_The_Winner
}  // namespace Predict_The_Winner