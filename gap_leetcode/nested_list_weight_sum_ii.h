#pragma once
#include <iostream>
#include <vector>

namespace Nested_List_Weight_Sum_II
{
//  364.加权嵌套序列和 II
//  364.Nested List Weight Sum II
//  https://leetcode-cn.com/problems/nested-list-weight-sum-ii/
using std::vector;
class NestedInteger
{
  public:
    // Constructor initializes an empty nested list.
    NestedInteger() : flag(false)
    {
    }
    // Constructor initializes a single integer.
    NestedInteger(int value) : flag(true), integer(value)
    {
    }
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const
    {
        return flag;
    }
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const
    {
        return integer;
    }
    // Set this NestedInteger to hold a single integer.
    void setInteger(int value)
    {
        integer = value;
    }
    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger& ni)
    {
        vec.push_back(ni);
    }
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger>& getList() const
    {
        return vec;
    }

  private:
    bool flag;
    int integer;
    vector<NestedInteger> vec;
};

class Solution
{
  public:
    int depthSumInverse(vector<NestedInteger>& nestedList)
    {
        int32_t depth = depthCalc(nestedList, 1);
        int32_t ret = 0;
        ret = valCalc(nestedList, depth);
        return ret;
    }
    int32_t valCalc(const vector<NestedInteger>& nestedList, int32_t depth)
    {
        int32_t ret = 0;
        for (const auto& item : nestedList)
        {
            if (item.isInteger())
            {
                ret += item.getInteger() * depth;
            }
            else
            {
                ret += valCalc(item.getList(), depth - 1);
            }
        }
        return ret;
    }

    int depthCalc(const vector<NestedInteger>& nestedList, int32_t depth)
    {
        int32_t bigDepth = depth;
        for (const auto& item : nestedList)
        {
            if (item.isInteger())
            {
                continue;
            }
            int32_t tmpDepth = depthCalc(item.getList(), depth + 1);
            if (tmpDepth > bigDepth)
            {
                bigDepth = tmpDepth;
            }
        }
        return bigDepth;
    }
    static void Test()
    {
        NestedInteger a(6);
        NestedInteger b;
        b.add(a);
        NestedInteger c(4);
        NestedInteger d;
        d.add(c);
        d.add(b);
        NestedInteger e(1);
        NestedInteger f;
        f.add(e);
        f.add(d);
        Solution solution;
        std::cout << "=============" << std::endl;
        std::cout << solution.depthCalc(f.getList(), 1) << std::endl;
        std::cout << solution.valCalc(f.getList(), solution.depthCalc(f.getList(), 1)) << std::endl;
        std::cout << "=============" << std::endl;
    }
};
}  // namespace Nested_List_Weight_Sum_II