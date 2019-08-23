#pragma once
#include <iostream>
#include <vector>

namespace Sparse_Matrix_Multiplication
{
using std::vector;
//  311.Ï¡Êè¾ØÕóµÄ³Ë·¨
//  311.Sparse Matrix Multiplication
class Solution
{
  public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B)
    {
        vector<vector<int>> ret;
        int32_t row = A.size();
        if (0 == row)
        {
            return ret;
        }
        int32_t col = B[0].size();
        int32_t tmp = B.size();
        ret.resize(row);
        for (auto& item : ret)
        {
            item.resize(col);
        }
        // for (int32_t idx = 0; idx < row; ++idx)
        //{
        //    for (int32_t idy = 0; idy < col; ++idy)
        //    {
        //        for (int32_t t = 0; t < tmp; ++t)
        //        {
        //            ret[idx][idy] += A[idx][t] * B[t][idy];
        //        }
        //    }
        //}
        for (int32_t idx = 0; idx < row; ++idx)
        {
            for (int32_t t = 0; t < tmp; ++t)
            {
                if (0 == A[idx][t])
                {
                    continue;
                }
                for (int32_t idy = 0; idy < col; ++idy)
                {
                    if (0 == B[t][idy])
                    {
                        continue;
                    }
                    ret[idx][idy] += A[idx][t] * B[t][idy];
                }
            }
        }
        return ret;
    }
    static void Test()
    {
        vector<vector<int>> a = {{1, 0, 0}, {-1, 0, 3}};
        vector<vector<int>> b = {{7, 0, 0}, {0, 0, 0}, {0, 0, 1}};
        Solution solution;
        std::cout << "=============" << std::endl;
        auto ret = solution.multiply(a, b);
        for (const auto& item : ret)
        {
            for (const auto& elem : item)
            {
                std::cout << elem << " ";
            }
            std::cout << std::endl;
        }
        std::cout << "=============" << std::endl;
    };
};
}  // namespace Sparse_Matrix_Multiplication