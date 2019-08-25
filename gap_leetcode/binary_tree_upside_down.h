#pragma once
#include <iostream>
#include <queue>
#include <vector>

namespace Binary_Tree_Upside_Down
{
//  156.上下翻转二叉树
//  156.Binary Tree Upside Down
//  https://leetcode-cn.com/problems/binary-tree-upside-down/

// Definition for a binary tree node.
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
    TreeNode* upsideDownBinaryTree(TreeNode* root)
    {
        if (nullptr == root || nullptr == root->left)
        {
            return root;
        }
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        TreeNode* newRoot = upsideDownBinaryTree(left);
        left->left = right;
        left->right = root;
        root->left = nullptr;
        root->right = nullptr;
        return newRoot;
    }
    static void traverse(TreeNode* root, int32_t idx, int32_t cnt)
    {
        std::queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            std::cout << node->val << " ";
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }
    }
    static int32_t count(TreeNode* root)
    {
        if (nullptr == root)
        {
            return 0;
        }
        int32_t cnt = 1;
        cnt += count(root->left);
        cnt += count(root->right);
        return cnt;
    }
    static TreeNode* create(int32_t val[], int32_t from, int32_t to)
    {
        if (from >= to)
        {
            return nullptr;
        }
        TreeNode* node = new TreeNode(val[from - 1]);
        node->left = create(val, from << 1, to);
        node->right = create(val, (from << 1) + 1, to);
        return node;
    }
    static void Test()
    {
        std::cout << "=============" << std::endl;
        int32_t val[] = {1, 2, 3, 4, 5, 6, 7};
        TreeNode* root = Solution::create(val, 1, 8);
        std::cout << Solution::count(root) << std::endl;
        Solution::traverse(root, 1, Solution::count(root));
        std::cout << std::endl;
        Solution solution;
        TreeNode* node = solution.upsideDownBinaryTree(root);
        Solution::traverse(node, 1, Solution::count(node));
        std::cout << "=============" << std::endl;
    }
};
}  // namespace Binary_Tree_Upside_Down