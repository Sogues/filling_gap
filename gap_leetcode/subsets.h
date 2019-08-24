#pragma once
#include <vector>

namespace Subsets
{
using std::vector;
//  78.×Ó¼¯
//  78.Subsets
//  https://leetcode-cn.com/problems/subsets/
class Solution
{
  public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> out;
        vector<int> result;
        out.push_back(result);
        func(nums, result, 0, nums.size(), out);
        return out;
    }
    void func(vector<int>& nums, vector<int>& result, int32_t from, int32_t to, vector<vector<int>>& out)
    {
        for (; from < to; ++from)
        {
            result.push_back(nums[from]);
            func(nums, result, from + 1, to, out);
            out.push_back(result);
            result.pop_back();
        }
    }
    static void Test()
    {
        std::cout << "=============" << std::endl;
        Solution solution;
        vector<int> nums = {1, 2, 3};
        auto out = solution.subsets(nums);
        (void)out;
        std::cout << "=============" << std::endl;
    }
};
}  // namespace Subsets