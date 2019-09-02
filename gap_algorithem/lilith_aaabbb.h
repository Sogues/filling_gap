#pragma once

namespace Lilith_AAABBB
{
class Solution
{
  public:
    void extension(int32_t num)
    {
        char* out = new char[(num << 1) + 1];
        out[(num << 2)] = '\0';
        func(out, num, 0, 0, 0);
        delete[] out;
    }
    void func(char* out, int32_t num, int32_t floor, int32_t up, int32_t down)
    {
        if (floor >= (num << 1))
        {
            std::cout << out << std::endl;
        }
        if (up < num)
        {
            out[floor] = '{';
            func(out, num, floor + 1, up + 1, down);
        }
        if (up > down)
        {
            out[floor] = '}';
            func(out, num, floor + 1, up, down + 1);
        }
    }
    static void Test()
    {
        std::cout << "=============" << std::endl;
        {
            Solution solution;
            solution.extension(3);
        }
        std::cout << "=============" << std::endl;
    }
};
}  // namespace Lilith_AAABBB