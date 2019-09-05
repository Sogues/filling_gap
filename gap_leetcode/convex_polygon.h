#pragma once

#include <iostream>
#include <vector>

namespace Convex_Polygon
{
//  469.Í¹¶à±ßÐÎ
//  469.Convex Polygon
//  https://leetcode-cn.com/problems/convex-polygon/
using std::vector;
class Solution
{
  public:
    bool isConvex(vector<vector<int>>& points)
    {
        int32_t size = points.size();
        int32_t sign = 0;
        for (int32_t idx = 0; idx < size; ++idx)
        {
            int32_t x1 = points[(idx + 1) % (size)][0] - points[idx][0];
            int32_t y1 = points[(idx + 1) % (size)][1] - points[idx][1];
            int32_t x2 = points[(idx + 2) % (size)][0] - points[idx][0];
            int32_t y2 = points[(idx + 2) % (size)][1] - points[idx][1];
            int32_t val = x1 * y2 - x2 * y1;
            if (0 == val)
            {
                continue;
            }
            if (val * sign < 0)
            {
                return false;
            }
            sign = val > 0 ? 1 : -1;
        }
        return true;
    }
    static void Test()
    {
        std::cout << "=============" << std::endl;
        {
            vector<vector<int>> points = {{0, 0}, {0, 1}, {1, 1}, {1, 0}};
            Solution solution;
            std::cout << solution.isConvex(points) << std::endl;
        }
        std::cout << "=============" << std::endl;
        {
            vector<vector<int>> points = {{0, 0}, {0, 10}, {10, 10}, {10, 0}, {5, 5}};
            Solution solution;
            std::cout << solution.isConvex(points) << std::endl;
        }
        std::cout << "=============" << std::endl;
    }
};
}  // namespace Convex_Polygon