#pragma once
#include <iostream>

namespace Reverse_Linked_List_II
{
//  92.反转链表 II
//  92.Reverse Linked List II
//  https://leetcode-cn.com/problems/reverse-linked-list-ii/comments/
// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL)
    {
    }
};

class Solution
{
  public:
    ListNode* reverseBetween(ListNode* head, int m, int n)
    {
        ListNode *pre = nullptr, *cur = head, *after = nullptr;
        int32_t idx = 1;
        while (idx++ < m)
        {
            pre = cur;
            cur = cur->next;
        }
        after = pre;
        while (m++ <= n)
        {
            ListNode* tmp = cur->next;
            cur->next = after;
            after = cur;
            cur = tmp;
        }
        if (nullptr != pre)
        {
            pre->next->next = cur;
            pre->next = after;
        }
        else
        {
            head->next = cur;
            head = after;
        }
        return head;
    }
    static void traverse(ListNode* head)
    {
        while (head)
        {
            std::cout << head->val << "->";
            head = head->next;
        }
        std::cout << "NULL" << std::endl;
    }
    static void Test()
    {
        std::cout << "=============" << std::endl;
        ListNode* head = new ListNode(1);
        ListNode* p = head;
        head->next = new ListNode(2);
        head = head->next;
        head->next = new ListNode(3);
        head = head->next;
        head->next = new ListNode(4);
        head = head->next;
        head->next = new ListNode(5);
        head = head->next;
        Solution::traverse(p);
        std::cout << "=============" << std::endl;
        Solution solution;
        // Solution::traverse(solution.reverseBetween(p, 2, 4));
        // Solution::traverse(solution.reverseBetween(p, 1, 1));
        // Solution::traverse(solution.reverseBetween(p, 2, 2));
        // Solution::traverse(solution.reverseBetween(p, 5, 5));
        // Solution::traverse(solution.reverseBetween(p, 1, 5));
        // Solution::traverse(solution.reverseBetween(p, 1, 4));
        Solution::traverse(solution.reverseBetween(p, 2, 5));
        std::cout << "=============" << std::endl;
    }
};
}  // namespace Reverse_Linked_List_II