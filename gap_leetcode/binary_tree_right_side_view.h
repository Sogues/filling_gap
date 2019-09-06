#pragma once

#include <iostream>
#include <queue>
#include <vector>

namespace Binary_Tree_Right_Side_View
{
//  199.¶þ²æÊ÷µÄÓÒÊÓÍ¼
//  199.Binary Tree Right Side View
//  https://leetcode-cn.com/problems/binary-tree-right-side-view/
using std::vector;
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
    vector<int> rightSideView(TreeNode* root)
    {
        vector<int> out;
        if (nullptr == root)
        {
            return out;
        }
        std::queue<TreeNode*> s;
        s.push(root);
        while (!s.empty())
        {
            out.push_back(s.back()->val);
            int32_t size = s.size();
            while (size--)
            {
                TreeNode* node = s.front();
                s.pop();
                if (node->left)
                {
                    s.push(node->left);
                }
                if (node->right)
                {
                    s.push(node->right);
                }
            }
        }
        return out;
    }
    static void Test()
    {
        std::cout << "=============" << std::endl;
        {
            TreeNode* root = new TreeNode(1);
            root->left = new TreeNode(2);
            root->right = new TreeNode(3);
            root->left->right = new TreeNode(5);
            root->right->right = new TreeNode(4);
            Solution solution;
            for (const auto& item : solution.rightSideView(root))
            {
                std::cout << item << ",";
            }
            std::cout << std::endl;
        }
        std::cout << "=============" << std::endl;
    }
};
}  // namespace Binary_Tree_Right_Side_View