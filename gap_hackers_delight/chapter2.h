#include <algorithm>
#include <iostream>
#include <string>

namespace Chapter2
{
class Solution
{
  public:
    static int32_t bianry2int(std::string val)
    {
        int32_t out = 0;
        for (const auto& item : val)
        {
            out = (out << 1) + (item - '0');
        }
        return out;
    }
    static std::string int2binary(uint32_t val)
    {
        std::string out;
        while (val)
        {
            out += '0' + (val & 1);
            val >>= 1;
        }
        std::reverse(out.begin(), out.end());
        return out;
    }
    static void bianry2int_Test()
    {
        std::cout << Solution::bianry2int("000001") << std::endl;
        std::cout << Solution::int2binary(Solution::bianry2int("000001")) << std::endl;
        std::cout << Solution::bianry2int("000010") << std::endl;
        std::cout << Solution::int2binary(Solution::bianry2int("000010")) << std::endl;
        std::cout << Solution::bianry2int("001000") << std::endl;
        std::cout << Solution::int2binary(Solution::bianry2int("001000")) << std::endl;
        std::cout << Solution::bianry2int("101010") << std::endl;
        std::cout << Solution::int2binary(Solution::bianry2int("101010")) << std::endl;
    }
    static void Chapter2_1()
    {
#define IDX 12
#if (1 == IDX)
        // ���Ҳ��1��0
        {
            std::string testVal = "01011110";
            int32_t x = bianry2int(testVal);
            std::cout << testVal << std::endl;
            std::cout << int2binary(x & (x - 1)) << std::endl;
        }
#endif
#if (2 == IDX)
        // ���Ҳ��0��1
        {
            std::string testVal = "1011110";
            int32_t x = bianry2int(testVal);
            std::cout << testVal << std::endl;
            std::cout << int2binary(x | (x + 1)) << std::endl;
        }
#endif
#if (3 == IDX)
        // β��������1���0
        {
            std::string testVal = "1011111";
            int32_t x = bianry2int(testVal);
            std::cout << testVal << std::endl;
            std::cout << int2binary(x & (x + 1)) << std::endl;
        }
#endif
#if (4 == IDX)
        // β��������0���1
        {
            std::string testVal = "10100000";
            int32_t x = bianry2int(testVal);
            std::cout << testVal << std::endl;
            std::cout << int2binary(x | (x - 1)) << std::endl;
        }
        {
            std::string testVal = "0";
            int32_t x = bianry2int(testVal);
            std::cout << testVal << std::endl;
            std::cout << int2binary(x | (x - 1)) << std::endl;
        }
#endif
#if (5 == IDX)
        // ���Ҳ��0��Ϊ1������λ�ñ�0
        {
            std::string testVal = "10101111";
            int32_t x = bianry2int(testVal);
            std::cout << testVal << std::endl;
            std::cout << int2binary(~x & (x + 1)) << std::endl;
        }
        {
            std::string testVal = "11110";
            int32_t x = bianry2int(testVal);
            std::cout << testVal << std::endl;
            std::cout << int2binary(~x & (x + 1)) << std::endl;
        }
#endif
#if (6 == IDX)
        // ���Ҳ��1��Ϊ0�������Ϊ1
        {
            std::string testVal = "10101000";
            int32_t x = bianry2int(testVal);
            std::cout << testVal << std::endl;
            std::cout << int2binary(~x | (x - 1)) << std::endl;
        }
        {
            std::string testVal = "1";
            int32_t x = bianry2int(testVal);
            std::cout << testVal << std::endl;
            std::cout << int2binary(~x | (x - 1)) << std::endl;
        }
#endif
#if (7 == IDX)
        // β��������0��Ϊ1�������Ϊ0
        {
            std::string testVal = "10101000";
            int32_t x = bianry2int(testVal);
            std::cout << testVal << std::endl;
            std::cout << int2binary(~x & (x - 1)) << std::endl;
        }
        {
            std::string testVal = "1";
            int32_t x = bianry2int(testVal);
            std::cout << testVal << std::endl;
            std::cout << int2binary(~x & (x - 1)) << std::endl;
        }
#endif
#if (8 == IDX)
        // β��������1��Ϊ0�������Ϊ1
        {
            std::string testVal = "10100111";
            int32_t x = bianry2int(testVal);
            std::cout << testVal << std::endl;
            std::cout << int2binary(~x | (x + 1)) << std::endl;
        }
        {
            std::string testVal = "1";
            int32_t x = bianry2int(testVal);
            std::cout << testVal << std::endl;
            std::cout << int2binary(~x | (x + 1)) << std::endl;
        }
#endif
#if (9 == IDX)
        // ������ҵ�1�������Ϊ0
        {
            std::string testVal = "01011000";
            int32_t x = bianry2int(testVal);
            std::cout << testVal << std::endl;
            std::cout << int2binary(x & (-x)) << std::endl;
        }
        {
            std::string testVal = "1";
            int32_t x = bianry2int(testVal);
            std::cout << testVal << std::endl;
            std::cout << int2binary(x & (-x)) << std::endl;
        }
#endif
#if (10 == IDX)
        // ������ҵ�1�����Ҳ඼��1����඼��0
        {
            std::string testVal = "01011000";
            int32_t x = bianry2int(testVal);
            std::cout << testVal << std::endl;
            std::cout << int2binary(x ^ (x - 1)) << std::endl;
        }
        {
            std::string testVal = "1";
            int32_t x = bianry2int(testVal);
            std::cout << testVal << std::endl;
            std::cout << int2binary(x ^ (x - 1)) << std::endl;
        }
#endif
#if (11 == IDX)
        // ��ҵ�0 �������Ҳ඼��1����඼��0
        {
            std::string testVal = "01010111";
            int32_t x = bianry2int(testVal);
            std::cout << testVal << std::endl;
            std::cout << int2binary(x ^ (x + 1)) << std::endl;
        }
        {
            std::string testVal = "1";
            int32_t x = bianry2int(testVal);
            std::cout << testVal << std::endl;
            std::cout << int2binary(x ^ (x + 1)) << std::endl;
        }
#endif
#if (12 == IDX)
        // ��ҵ�0 �������Ҳ඼��1����඼��0
        {
            std::string testVal = "01010111";
            int32_t x = bianry2int(testVal);
            std::cout << testVal << std::endl;
            std::cout << int2binary(x ^ (x + 1)) << std::endl;
        }
        {
            std::string testVal = "1";
            int32_t x = bianry2int(testVal);
            std::cout << testVal << std::endl;
            std::cout << int2binary(x ^ (x + 1)) << std::endl;
        }
#endif
    }
};
}  // namespace Chapter2