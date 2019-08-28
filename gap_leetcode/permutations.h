#pragma once
#include <iostream>
#include <vector>

namespace Permutation
{
//  46.全排列
//  46.Permutations
//  https://leetcode-cn.com/problems/permutations/
using std::vector;
class Solution
{
  public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> out;
        traverse(out, nums, 0, nums.size());
        return out;
    }
    void traverse(vector<vector<int>>& out, vector<int>& nums, int32_t from, int32_t size)
    {
        if (from >= size)
        {
            out.push_back(nums);
            return;
        }
        for (int32_t idx = from; idx < size; ++idx)
        {
            if (idx != from)
            {
                nums[idx] = nums[idx] ^ nums[from];
                nums[from] = nums[idx] ^ nums[from];
                nums[idx] = nums[idx] ^ nums[from];
                traverse(out, nums, from + 1, size);
                nums[idx] = nums[idx] ^ nums[from];
                nums[from] = nums[idx] ^ nums[from];
                nums[idx] = nums[idx] ^ nums[from];
            }
            else
            {
                traverse(out, nums, from + 1, size);
            }
        }
    }
    static void Test()
    {
        std::cout << "=============" << std::endl;
        Solution solution;
        vector<int> nums = {1, 2, 3};
        for (const auto& item : solution.permute(nums))
        {
            std::cout << "[";
            for (const auto& elem : item)
            {
                std::cout << elem << ",";
            }
            std::cout << "]" << std::endl;
        }
    }
};  // namespace Permutation
}  // namespace Permutation