#pragma once
#include <iostream>
#include <vector>

namespace Maximum_Binary_Tree
{
using std::vector;
//  654.×î´ó¶þ²æÊ÷
//  654.Maximum Binary Tree
//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {
    }
};
class Solution
{
  public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums)
    {
        return create(nums, 0, nums.size());
    }
    TreeNode* create(vector<int>& nums, int32_t from, int32_t to)
    {
        int32_t idx;
        TreeNode* root = Solution::GetMaxNode(nums, from, to, idx);
        if (nullptr == root)
        {
            return nullptr;
        }
        root->left = create(nums, from, idx);
        root->right = create(nums, idx + 1, to);
        return root;
    }
    static TreeNode* GetMaxNode(vector<int>& nums, int32_t from, int32_t to, int32_t& idx)
    {
        idx = -1;
        int32_t maxVal = (~(1)) + 1;
        while (from < to)
        {
            if (maxVal >= nums[from])
            {
                ++from;
                continue;
            }
            maxVal = nums[from];
            idx = from++;
        }
        if (-1 == idx)
        {
            return nullptr;
        }
        return new TreeNode(maxVal);
    }
    static void traverse(TreeNode* node)
    {
        if (nullptr == node)
        {
            return;
        }
        traverse(node->left);
        std::cout << node->val << ",";
        traverse(node->right);
    }
    static void Test()
    {
        std::cout << "=============" << std::endl;
        Solution solution;
        vector<int> val = {3, 2, 1, 6, 0, 5};
        Solution::traverse(solution.constructMaximumBinaryTree(val));
        std::cout << std::endl;
        std::cout << "=============" << std::endl;
    }
};
}  // namespace Maximum_Binary_Tree
