#pragma once
#include <algorithm>
#include <queue>
#include <vector>

namespace Reveal_Cards_In_Increasing_Order
{
//  950.∞¥µ›‘ˆÀ≥–Úœ‘ æø®≈∆
//  950.Reveal Cards In Increasing Order
//  https://leetcode-cn.com/problems/reveal-cards-in-increasing-order/
using std::vector;
class Solution
{
  public:
    vector<int> deckRevealedIncreasing(vector<int>& deck)
    {
        int32_t size = deck.size();
        if (0 == size || 1 == size)
        {
            return deck;
        }
        vector<int> ret;
        std::queue<int> contain;
        ret.resize(size);
        std::sort(deck.rbegin(), deck.rend());
        for (const auto& item : deck)
        {
            if (!contain.empty())
            {
                contain.push(contain.front());
                contain.pop();
            }
            contain.push(item);
        }
        while (!contain.empty())
        {
            ret[--size] = contain.front();
            contain.pop();
        }
        return ret;
    }
    static void Test()
    {
        vector<int> deck1 = {17, 13, 11, 2, 3, 5, 7};
        Solution solution;
        std::cout << "=============" << std::endl;
        for (const auto& item : solution.deckRevealedIncreasing(deck1))
        {
            std::cout << item << ", ";
        }
        std::cout << std::endl;
        std::cout << "=============" << std::endl;
        vector<int> deck2 = {7};
        std::cout << "=============" << std::endl;
        for (const auto& item : solution.deckRevealedIncreasing(deck2))
        {
            std::cout << item << ", ";
        }
        std::cout << std::endl;
        std::cout << "=============" << std::endl;
        vector<int> deck3 = {7, 8};
        std::cout << "=============" << std::endl;
        for (const auto& item : solution.deckRevealedIncreasing(deck3))
        {
            std::cout << item << ", ";
        }
        std::cout << std::endl;
        std::cout << "=============" << std::endl;
        vector<int> deck4 = {17, 13, 11, 2, 3, 5};
        std::cout << "=============" << std::endl;
        for (const auto& item : solution.deckRevealedIncreasing(deck4))
        {
            std::cout << item << ", ";
        }
        std::cout << std::endl;
        std::cout << "=============" << std::endl;
    }
};
}  // namespace Reveal_Cards_In_Increasing_Order