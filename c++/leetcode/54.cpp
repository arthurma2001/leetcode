/*
  54. Spiral Matrix
  
  Given an m x n matrix, return all elements of the matrix in spiral order.
  Example1 - 
  Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
  Output: [1,2,3,6,9,8,7,4,5]

  Example 2 -- 
  Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
  Output: [1,2,3,4,8,12,11,10,9,5,6,7]
**/

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <tuple>
#include <stack>
#include <algorithm>
using namespace std;
#include "basic/utils.hpp"
#include "basic/ListNode.hpp"
using namespace leetcode;
using namespace basic;

namespace
{
    class Solution {
        vector<int> method1 (const vector<vector<int>>& matrix) {
            int m = matrix.size();
            int n = matrix[0].size();
            
            vector<vector<int>> flags;
            vector<int> false_flags;
            false_flags.resize(n);
            std::fill (false_flags.begin(), false_flags.end(), false);
            for (int i = 0; i < m; i++)
                flags.push_back (false_flags);

            vector<int> olst;
            int cnt = 0, k = 0;
            while (cnt < m * n)
            {
                int i = k;
                for (int j = k; j < n-k; j++)
                {
                    olst.push_back(matrix[i][j]);
                    cnt ++;
                }
                if (cnt == m * n) continue;
                
                int j = n-k-1;
                for (int i = k+1; i < m-k-1; i++)
                {
                    olst.push_back(matrix[i][j]);
                    cnt ++;
                }
                if (cnt == m * n) continue;
                
                i = m-k-1;
                for (int j = n-k-1; j >= k; j--)
                {
                    olst.push_back(matrix[i][j]);
                    cnt ++;
                }
                if (cnt == m * n) continue;

                j = k;
                for (int i = m-k-2; i >= k+1; i--)
                {
                    olst.push_back(matrix[i][j]);
                    cnt ++;
                }
                k++;
            }
            return olst;
        }

        vector<int> method2 (const vector<vector<int>>& matrix) {
            int m = matrix.size();
            int n = matrix[0].size();
            
            vector<bool> false_flags (n, false);
            vector<vector<bool>> flags (m, false_flags);
            
            vector<int> olst;
            int x = 0, y = 0;
            while (m > 0 && n > 0)
            {
                if (m == 1)
                {
                    for (int i = 0; i < n; i++)
                        olst.push_back(matrix[x][y++]);
                    break;
                }
                else if (n == 1)
                {
                    for (int i = 0; i < m; i++)
                        olst.push_back(matrix[x++][y]);
                    break;
                }
                    
                for (int i = 0; i < n-1; i++)
                    olst.push_back(matrix[x][y++]);
                for (int i = 0; i < m-1; i++)
                    olst.push_back(matrix[x++][y]);
                for (int i = 0; i < n-1; i++)
                    olst.push_back(matrix[x][y--]);
                for (int i = 0; i < m-1; i++)
                    olst.push_back(matrix[x--][y]);
                x++;  y++;
                m -= 2;
                n -= 2;
            }
            return olst;
        }

        vector<int> method3 (const vector<vector<int>>& matrix) {
            int m = matrix.size();
            int n = matrix[0].size();
            
            vector<bool> false_flags (n, false);
            vector<vector<bool>> flags (m, false_flags);
            
            vector<int> olst;
            int x = 0, y = 0;
            while (m > 0 && n > 0)
            {
                for (int i = 0; i < n-1; i++)
                    olst.push_back(matrix[x][y++]);
                for (int i = 0; i < m-1; i++)
                    olst.push_back(matrix[x++][y]);
                for (int i = 0; i < n-1; i++)
                    olst.push_back(matrix[x][y--]);
                for (int i = 0; i < m-1; i++)
                    olst.push_back(matrix[x--][y]);
                x++;  y++;
                m -= 2;
                n -= 2;
            }
            return olst;
        }
        

    public:
        vector<int> spiralOrder(const vector<vector<int>>& matrix) {
            return method2 (matrix);
        }
    };    
}

int leetcode_54_main(int argc, char** argv)
{
    fprintf (stderr, "int leetcode_54_main()\n");
    Solution s1;
    
    vector<vector<int>> mat1 = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> mat2 = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    //vector<int> out_val1 = s1. spiralOrder(mat1);
    vector<int> out_val2 = s1. spiralOrder(mat2);

    //utils::dump_vector  ("Example1", out_val1);
    utils::dump_vector  ("Example2", out_val2);

    return 0;
}
