#pragma once

namespace Linked_List_Random_Node
{
//  382.链表随机节点
//  382.Linked List Random Node
//  https://leetcode-cn.com/problems/linked-list-random-node/
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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) : head_(head)
    {
    }

    /** Returns a random node's value. */
    int getRandom()
    {
        if (nullptr == head_)
        {
            return 0;
        }
        int32_t res = head_->val;
        int32_t idx = 1;
        ListNode* cur = head_;
        while (nullptr != cur->next)
        {
            cur = cur->next;
            if (rand() % (idx + 1) == idx)
            {
                res = cur->val;
            }
            ++idx;
        }
        return res;
    }
    static void Test()
    {
        std::cout << "=============" << std::endl;
    }

  private:
    ListNode* head_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
}  // namespace Linked_List_Random_Node
