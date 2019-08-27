#pragma once
#include <stack>
#include <string>

namespace Decode_String
{
//  394.字符串解码
//  394.Decode String
//  https://leetcode-cn.com/problems/decode-string/
using std::string;
class Solution
{
  public:
    string decodeString(string s)
    {
        string out, num;
        std::stack<int32_t> st;
        std::stack<string> sts;
        for (const auto& item : s)
        {
            if (item >= '0' && item <= '9')
            {
                num += item;
            }
            else if (item == '[')
            {
                st.push(atoi(num.c_str()));
                string().swap(num);
                sts.push("");
            }
            else if (item == ']')
            {
                int32_t times = st.top();
                string val = sts.top(), tmp;
                st.pop();
                sts.pop();
                for (int32_t idx = 0; idx < times; ++idx)
                {
                    tmp += val;
                }
                if (sts.empty())
                {
                    out += tmp;
                }
                else
                {
                    sts.top() += tmp;
                }
            }
            else
            {
                if (st.empty())
                {
                    out += item;
                }
                else
                {
                    sts.top() += item;
                }
            }
        }
        return out;
    }
    static void Test()
    {
        std::cout << "=============" << std::endl;
        Solution solutoin;
        std::cout << solutoin.decodeString("3[a]2[bc]") << std::endl;
        std::cout << solutoin.decodeString("3[a2[c]]") << std::endl;
        std::cout << solutoin.decodeString("2[abc]3[cd]ef") << std::endl;
        std::cout << solutoin.decodeString("fe23[a]2[bc]") << std::endl;
        std::cout << "=============" << std::endl;
    }
};
}  // namespace Decode_String