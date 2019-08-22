#pragma once
#include <vector>

namespace Max_Increase_To_Keep_City_Skyline
{
using std::vector;
//  algorithm
//  807.保持城市天际线
//  807.Max Increase to Keep City Skyline
//  https://leetcode.com/problemset/all/?search=807
class Solution
{
  public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid)
    {
        vector<int> vertical, horizontal;
        int32_t size = grid.size();
        vertical.resize(size);
        horizontal.resize(size);
        int32_t idx = 0, idy = 0, ret = 0;

        for (idx = 0; idx < size; ++idx)
        {
            int32_t maxv = 0;
            int32_t maxh = 0;
            for (idy = 0; idy < size; ++idy)
            {
                if (maxv < grid[idy][idx])
                {
                    maxv = grid[idy][idx];
                }
                if (maxh < grid[idx][idy])
                {
                    maxh = grid[idx][idy];
                }
            }
            vertical[idx] = maxv;
            horizontal[idx] = maxh;
        }

        for (idx = 0; idx < size; ++idx)
        {
            for (idy = 0; idy < size; ++idy)
            {
                if (vertical[idx] > horizontal[idy])
                {
                    ret += horizontal[idy] - grid[idx][idy];
                }
                else
                {
                    ret += vertical[idx] - grid[idx][idy];
                }
            }
        }
        return ret;
    }

    static void Test()
    {
        vector<vector<int>> grid = {{3, 0, 8, 4}, {2, 4, 5, 7}, {9, 2, 6, 3}, {0, 3, 1, 0}};
        Solution solution;
        std::cout << "=============" << std::endl;
        std::cout << solution.maxIncreaseKeepingSkyline(grid) << std::endl;
        std::cout << "=============" << std::endl;
    }
};
}  // namespace Max_Increase_To_Keep_City_Skyline
