#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace Output_Contest_Matches
{
using std::string;
//  544.输出比赛匹配对
//  544.Output Contest Matches
//  https://leetcode-cn.com/problems/output-contest-matches/
class Solution
{
    template <typename ElemType>
    struct Elem
    {
        Elem()
        {
        }
        Elem& operator=(const ElemType& str)
        {
            val = str;
        }
        Elem& operator=(const char* str)
        {
            val = str;
        }
        Elem& operator=(int32_t idx)
        {
            std::ostringstream os;
            os << idx;
            val = os.str();
        }
        ElemType val;
    };

  public:
    string findContestMatch(int n)
    {
        if (0 == n)
        {
            return "";
        }
        if (1 == n)
        {
            return "1";
        }
        std::vector<Elem<string>> contain;
        contain.resize(n);

        for (int32_t idx = 0; idx < n; ++idx)
        {
            contain[idx] = idx + 1;
        }
        return Calc(contain);
    }

    string Calc(std::vector<Elem<string>>& val)
    {
        int32_t size = val.size();
        if (1 == size)
        {
            return val[0].val;
        }
        int32_t depth = Solution::GetDepth(size);
        int32_t fullSize = 1 << depth;
        int32_t halfSize = fullSize >> 1;
        std::vector<Elem<string>> contain;
        contain.resize(halfSize);
        for (int32_t idx = 0; idx < halfSize; ++idx)
        {
            auto& elem = contain[idx];
            elem.val = "(" + val[idx].val;
            if (fullSize - idx - 1 < size)
            {
                elem.val += "," + val[fullSize - idx - 1].val;
            }
            elem.val += ")";
        }
        return Calc(contain);
    }

    static inline int32_t GetDepth(int32_t n)
    {
        if (0 == n--)
        {
            return 1;
        }
        int32_t ret = 0;
        while (n)
        {
            ++ret;
            n >>= 1;
        }
        return ret;
    }

    static void Test()
    {
        std::cout << "=============" << std::endl;
        std::cout << (1 << Solution::GetDepth(0)) << std::endl;
        std::cout << (1 << Solution::GetDepth(7)) << std::endl;
        std::cout << (1 << Solution::GetDepth(8)) << std::endl;
        std::cout << (1 << Solution::GetDepth(9)) << std::endl;
        std::cout << "=============" << std::endl;
        Solution solution;
        std::cout << solution.findContestMatch(0) << std::endl;
        std::cout << solution.findContestMatch(1) << std::endl;
        std::cout << solution.findContestMatch(2) << std::endl;
        std::cout << solution.findContestMatch(4) << std::endl;
        std::cout << solution.findContestMatch(5) << std::endl;
        std::cout << solution.findContestMatch(7) << std::endl;
        std::cout << solution.findContestMatch(8) << std::endl;
        std::cout << solution.findContestMatch(9) << std::endl;
        std::cout << solution.findContestMatch(16) << std::endl;
        std::cout << "=============" << std::endl;
    }
};
}  // namespace Output_Contest_Matches