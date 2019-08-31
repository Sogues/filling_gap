#pragma once
#include <iostream>
#include <queue>
#include <vector>

namespace The_Maze_II
{
//  505.รินฌ II
//  505.The Maze II
//  https://leetcode-cn.com/problems/the-maze-ii/
using std::vector;
class Solution
{
  public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination)
    {
        int32_t rows = maze.size(), cols = maze[0].size();
        vector<vector<int32_t>> stepInfo(rows, (vector<int32_t>(cols, 0)));
        std::queue<std::pair<int32_t, int32_t>> history;
        history.push({start[0], start[1]});

        int32_t row = 0, col = 0, tmpRow = 0, tmpCol = 0, steps = 0;
        while (!history.empty())
        {
            auto& elem = history.front();
            row = elem.first, col = elem.second;
            history.pop();
            {
                tmpRow = row, tmpCol = col;
                while (tmpRow + 1 < rows && !maze[tmpRow + 1][tmpCol])
                {
                    ++tmpRow;
                }
                steps = tmpRow - row + stepInfo[row][col];
                if (tmpRow != row && (!stepInfo[tmpRow][tmpCol] || steps < stepInfo[tmpRow][tmpCol]))
                {
                    history.push({tmpRow, tmpCol});
                    stepInfo[tmpRow][tmpCol] = steps;
                }
            }
            {
                tmpRow = row, tmpCol = col;
                while (tmpRow > 0 && !maze[tmpRow - 1][tmpCol])
                {
                    --tmpRow;
                }
                steps = row - tmpRow + stepInfo[row][col];
                if (tmpRow != row && (!stepInfo[tmpRow][tmpCol] || steps < stepInfo[tmpRow][tmpCol]))
                {
                    history.push({tmpRow, tmpCol});
                    stepInfo[tmpRow][tmpCol] = steps;
                }
            }
            {
                tmpRow = row, tmpCol = col;
                while (tmpCol + 1 < cols && !maze[tmpRow][tmpCol + 1])
                {
                    ++tmpCol;
                }
                steps = tmpCol - col + stepInfo[row][col];
                if (tmpCol != col && (!stepInfo[tmpRow][tmpCol] || steps < stepInfo[tmpRow][tmpCol]))
                {
                    history.push({tmpRow, tmpCol});
                    stepInfo[tmpRow][tmpCol] = steps;
                }
            }
            {
                tmpRow = row, tmpCol = col;
                while (tmpCol > 0 && !maze[tmpRow][tmpCol - 1])
                {
                    --tmpCol;
                }
                steps = col - tmpCol + stepInfo[row][col];
                if (tmpCol != col && (!stepInfo[tmpRow][tmpCol] || steps < stepInfo[tmpRow][tmpCol]))
                {
                    history.push({tmpRow, tmpCol});
                    stepInfo[tmpRow][tmpCol] = steps;
                }
            }
        }
        steps = stepInfo[destination[0]][destination[1]];
        return steps ? steps : -1;
    }
    static void Test()
    {
        std::cout << "=============" << std::endl;
        {
            vector<vector<int32_t>> maze = {
                {0, 0, 1, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 1, 0}, {1, 1, 0, 1, 1}, {0, 0, 0, 0, 0}};
            vector<int32_t> start = {0, 4};
            vector<int32_t> destination = {4, 4};
            Solution solution;
            std::cout << solution.shortestDistance(maze, start, destination) << std::endl;
        }
        std::cout << "=============" << std::endl;
        {
            vector<vector<int32_t>> maze = {
                {0, 0, 1, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 1, 0}, {1, 1, 0, 1, 1}, {0, 0, 0, 0, 0}};
            vector<int32_t> start = {0, 4};
            vector<int32_t> destination = {3, 2};
            Solution solution;
            std::cout << solution.shortestDistance(maze, start, destination) << std::endl;
        }
        std::cout << "=============" << std::endl;
    }
};
}  // namespace The_Maze_II
