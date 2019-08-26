#pragma once
#include <iostream>

namespace Reverse_Linked_List
{
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
    ListNode* reverseList(ListNode* head)
    {
        // return recursive(head);
        return iteration(head);
    }
    ListNode* recursive(ListNode* head)
    {
        if (nullptr == head || nullptr == head->next)
        {
            return head;
        }
        auto out = recursive(head->next);
        head->next->next = head;
        head->next = nullptr;
        return out;
    }
    ListNode* iteration(ListNode* head)
    {
        ListNode* pre = nullptr;
        while (head)
        {
            ListNode* tmp = head->next;
            head->next = pre;
            pre = head;
            head = tmp;
        }
        return pre;
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
        Solution::traverse(solution.reverseList(p));
        std::cout << "=============" << std::endl;
    }
};
}  // namespace Reverse_Linked_List