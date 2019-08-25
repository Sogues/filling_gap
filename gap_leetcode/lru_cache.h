#pragma once
#include <iostream>
#include <unordered_map>

namespace LRU_Cache
{
//  146.LRU缓存机制
//  146.LRU Cache
//  https://leetcode-cn.com/problems/lru-cache/
class LRUCache
{
    struct Node_t
    {
        Node_t(int32_t k, int32_t v) : key(k), val(v), pre(nullptr), next(nullptr)
        {
        }
        Node_t()
        {
        }
        int32_t key;
        int32_t val;
        Node_t* pre;
        Node_t* next;
    };
    struct LinkList_t
    {
        LinkList_t(size_t cap) : size(0), capacity(cap)
        {
            head.next = &tail;
            tail.pre = &head;
        }
        Node_t head;
        Node_t tail;
        size_t size;
        size_t capacity;
    };
    static void push_front(LinkList_t* pList, Node_t* pNode)
    {
        pList->head.next->pre = pNode;
        pNode->next = pList->head.next;
        pNode->pre = &pList->head;
        pList->head.next = pNode;
        ++pList->size;
    }
    static Node_t* pop_back(LinkList_t* pList)
    {
        if (pList->tail.pre == &pList->head)
        {
            return nullptr;
        }
        Node_t* pNode = pList->tail.pre;
        pList->tail.pre = pNode->pre;
        pNode->pre->next = &pList->tail;
        --pList->size;
        return pNode;
    }
    static void pop(LinkList_t* pList, Node_t* pNode)
    {
        pNode->next->pre = pNode->pre;
        pNode->pre->next = pNode->next;
        --pList->size;
    }
    typedef std::unordered_map<int32_t, Node_t*> hash_contain_t;
#define INVALID_ID -1

  private:
    LinkList_t link_list;
    hash_contain_t contains;

  public:
    LRUCache(int capacity) : link_list(capacity)
    {
    }

    int get(int key)
    {
        hash_contain_t::iterator iter = contains.find(key);
        if (iter == contains.end())
        {
            return INVALID_ID;
        }
        pop(&link_list, iter->second);
        push_front(&link_list, iter->second);
        return iter->second->val;
    }

    void put(int key, int value)
    {
        hash_contain_t::iterator iter = contains.find(key);
        Node_t* pNode = nullptr;
        if (iter != contains.end())
        {
            pNode = iter->second;
            pNode->val = value;
            pop(&link_list, pNode);
        }
        else
        {
            pNode = new Node_t(key, value);
            contains[key] = pNode;
        }
        if (link_list.size >= link_list.capacity)
        {
            Node_t* pNode = pop_back(&link_list);
            contains.erase(pNode->key);
            delete pNode;
        }
        push_front(&link_list, pNode);
    }
    void traverse()
    {
        Node_t *pNext = link_list.head.next, *pTail = &link_list.tail;
        while (pNext != pTail)
        {
            std::cout << "[" << pNext->key << "," << pNext->val << "] ";
            pNext = pNext->next;
        }
        std::cout << std::endl;
    }
    static void Test()
    {
        std::cout << "=============" << std::endl;
        LRUCache cache(3);
        cache.put(1, 2);
        cache.put(2, 3);
        cache.put(3, 4);
        cache.put(4, 5);
        cache.traverse();
        std::cout << cache.get(1) << std::endl;
        std::cout << cache.get(2) << std::endl;
        cache.put(5, 6);
        std::cout << cache.get(1) << std::endl;
        cache.traverse();
        std::cout << "=============" << std::endl;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
}  // namespace LRU_Cache