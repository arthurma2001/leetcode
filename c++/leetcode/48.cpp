/*
48. Rotate Image
Medium

You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]

Example 2:
Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

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
        // method1 = {  { 3,6,9 },  { 2,5,8 },  { 1,4,7 },  } 
        void method1 (vector<vector<int>>& matrix)
        {
            if (matrix.size() == 0)
                return;
            
            // 0,0 --> (0, 2)     (i, j) --> (j, m-i-1)
            // 0,1 --> (1, 2)
            // 0,2 --> (2, 2)
            // 1,0 --> (0, 1)
            // 1,1 --> (1,1)
            // 1,2 --> (2, 1)
            // 2,0 --> (0, 0)
            // 2,1 --> (1, 0)
            // 2,2 --> (2, 0)
            // (i, j) ===> (?,?)
            
            auto mat2 = matrix;
            int n = matrix.size();
            int m = matrix[0].size();
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    mat2[j][m-i-1] = matrix[i][j];
                }
            }
            matrix = mat2;
            //utils::dump_vectors  ("method1", matrix);
        }

        // not working 
        void tmp_try_method1 (vector<vector<int>>& matrix)
        {
            if (matrix.size() == 0)
                return;

            int n = matrix.size();
            int m = matrix[0].size();

            int fill_cnt = 0;
            vector<std::pair<int,int>> seeds;
            for (int i = 0; i < m; i++)
                seeds.push_back (std::pair<int,int>(i,0));

            while (! seeds.empty())
            {
                std::pair<int,int> d = seeds.back();
                int i0 = d.first;
                int j0 = d.second;
                int v0 = matrix[i0][j0];
                seeds.pop_back();

                int prev_v = v0;
                int i = i0, j = j0;
                vector<std::tuple<int,int,int>> flst;
                fprintf (stderr, "(%d,%d) ", i, j);
                do
                {
                    int ti = j;
                    int tj = m-i-1;
                    fprintf (stderr, "(%d,%d) ", ti, tj);
                    
                    if (ti == i0 && tj == j0)
                        break;
                    int v1 = matrix[ti][tj];
                    flst.push_back({ti, tj, prev_v});
                    prev_v = v1;
                    i = ti, j = tj;
                }
                while (i != i0 || j != j0);
                flst.push_back({i0, j0, prev_v});
                fprintf (stderr, "\n");
                
                for (auto v : flst)
                {
                    int i = std::get<0>(v);
                    int j = std::get<1>(v);
                    int v1 = std::get<2>(v);
                    matrix[i][j] = v1;
                }
            }
            utils::dump_vectors  ("tmp_try_method1", matrix);
        }

        void clock_wise_rotate (vector<vector<int>>& matrix)
        {
            if (matrix.size() == 0)
                return;

            int n = matrix.size();
            int m = matrix[0].size();
            for (int i = 0; i < n; i++)
            {
                for (int j = i+1; j < m; j++)
                {
                    swap (matrix[i][j], matrix[j][i]);
                }
            }
            //utils::dump_vectors  ("clock_wise_rotate", matrix);
        }
        
        void method2 (vector<vector<int>>& matrix)
        {
            clock_wise_rotate (matrix);
            
            int n = matrix.size();
            int m = matrix[0].size();
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m/2; j++)
                {
                    swap (matrix[i][j], matrix[i][m-j-1]);
                }
            }
        }
        
    public:
        void rotate(vector<vector<int>>& matrix)
        {
            method2 (matrix);
        }
    };    
}

int leetcode_48_main(int argc, char** argv)
{
    fprintf (stderr, "int leetcode_48_main()\n");
    Solution s1;
    
    vector<vector<int>> mat1 = {{1,2,3},{4,5,6},{7,8,9}};
    s1.rotate (mat1);

    vector<vector<int>> mat2 = {{5,1,9,11},{2,4,8,10},
                                {13,3,6,7},{15,14,12,16}};
    s1.rotate (mat2);
    
    utils::dump_vectors  ("Example1", mat1);
    utils::dump_vectors  ("Example2", mat2);

    return 0;
}
