#pragma once
#include <iostream>
#include <vector>

namespace Spiral_Matrix_II
{
//  59.螺旋矩阵 II
//  59.Spiral Matrix II
//  https://leetcode-cn.com/problems/spiral-matrix-ii/
using std::vector;
class Solution
{
  public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> ret;
        ret.resize(n);
        for (auto& item : ret)
        {
            item.resize(n);
        }
        // int32_t start = 1, end = n * n + 1, e = 0;
        // while (start < end)
        //{
        //    for (int32_t idx = e; idx < n - e; ++idx)
        //    {
        //        ret[e][idx] = start++;
        //    }
        //    for (int32_t idx = e + 1; idx < n - e; ++idx)
        //    {
        //        ret[idx][n - e - 1] = start++;
        //    }
        //    for (int32_t idx = n - e - 2; idx >= e; --idx)
        //    {
        //        ret[n - e - 1][idx] = start++;
        //    }
        //    for (int32_t idx = n - e - 2; idx >= e + 1; --idx)
        //    {
        //        ret[idx][e] = start++;
        //    }
        //    ++e;
        //}
        int32_t start = 0, end = n * n, row = 0, col = 0, dirRow = 0, dirCol = 1;
        while (start++ < end)
        {
            ret[row][col] = start;
            /// 元素已经存在，转弯
            if (ret[(row + dirRow + n) % n][(col + dirCol + n) % n] > 0)
            {
                int32_t tmp = dirRow;
                dirRow = dirCol;
                dirCol = -tmp;
            }
            row = row + dirRow;
            col = col + dirCol;
        }
        return ret;
    }
    static void Test()
    {
        std::cout << "=============" << std::endl;
        Solution solution;
        for (const auto& item : solution.generateMatrix(3))
        {
            for (const auto& elem : item)
            {
                std::cout << elem << " ";
            }
            std::cout << std::endl;
        }
        std::cout << "=============" << std::endl;
        for (const auto& item : solution.generateMatrix(4))
        {
            for (const auto& elem : item)
            {
                std::cout << elem << " ";
            }
            std::cout << std::endl;
        }
        std::cout << "=============" << std::endl;
        for (const auto& item : solution.generateMatrix(5))
        {
            for (const auto& elem : item)
            {
                std::cout << elem << " ";
            }
            std::cout << std::endl;
        }
        std::cout << "=============" << std::endl;
    }
};
}  // namespace Spiral_Matrix_II