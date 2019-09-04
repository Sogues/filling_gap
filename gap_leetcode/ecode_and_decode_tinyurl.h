#pragma once
#include <cmath>
#include <iostream>
#include <string>
#include <unordered_map>

namespace Encode_And_Decode_TinyURL
{
//  535.Encode and Decode TinyURL
//  535.TinyURL 的加密与解密
//  https://leetcode-cn.com/problems/encode-and-decode-tinyurl/
using std::string;
class Solution
{
    // http://tinyurl.com/4e9iAk.

  private:
    std::unordered_map<int64_t, string> hash_;

  public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl)
    {
        int64_t hashVal = Solution::hash_string(longUrl);
        if (0 == this->hash_.count(hashVal))
        {
            this->hash_[hashVal] = longUrl;
        }
        return "http://tinyurl.com/" + Solution::integerToHex(hashVal);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl)
    {
        return hash_[hexToInteger(shortUrl.substr(19))];
    }
    static int64_t hash_string(string code)
    {
        int32_t idx = 1;
        int64_t ret = 0;
        for (const auto& item : code)
        {
            ret += 31 * idx + item;
        }
        return ret;
    }

    static string integerToHex(int64_t value)
    {
        char val_1[] = "0123456789abcdef";
        char val_2[] = "0123456789ABCDEF";
        (void)val_2;
        int64_t idx = 0;
        int64_t size = log(value) / log(16) + 1;
        string ret;
        ret.resize(size);
        while (idx < size)
        {
            int32_t mod = value - (value & ~((int64_t)15));
            ret[size - idx++ - 1] = val_1[mod];
            value >>= 4;
        }
        return ret;
    }

    static int64_t hexToInteger(string code)
    {
        int64_t ret = 0;
        for (const auto& item : code)
        {
            if (item <= '9')
            {
                ret = (item - '0') + (ret << 4);
            }
            else if (item <= 'f')
            {
                ret = 10 + (item - 'a') + (ret << 4);
            }
            else
            {
                ret = 10 + (item - 'A') + (ret << 4);
            }
        }
        return ret;
    }

    static void Test()
    {
        std::cout << "=============" << std::endl;
        int64_t val1 = 4231432442;
        std::cout << val1 << std::endl;
        std::cout << integerToHex(val1) << std::endl;
        std::cout << hexToInteger(integerToHex(val1)) << std::endl;
        std::cout << "=============" << std::endl;
        std::string code = "https://leetcode.com/problems/design-tinyurl";
        std::cout << code << std::endl;
        Solution solution;
        std::cout << solution.encode(code) << std::endl;
        std::cout << solution.decode(solution.encode(code)) << std::endl;
        std::cout << "=============" << std::endl;
    }
};
}  // namespace Encode_And_Decode_TinyURL
