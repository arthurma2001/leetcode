/*
  73. Set Matrix Zeroes
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

You must do it in place.
Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

 

Constraints:

    m == matrix.length
    n == matrix[0].length
    1 <= m, n <= 200
    -231 <= matrix[i][j] <= 231 - 1

 

Follow up:

    A straightforward solution using O(mn) space is probably a bad idea.
    A simple improvement uses O(m + n) space, but still not the best solution.
    Could you devise a constant space solution?

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
        void fillColZero (int j, vector<vector<int>>& m)   {
            int aj = j;
            for (int ai = 0; ai < m.size(); ai++)
                m[ai][aj] = 0;
        }
        
        void fillRowZero (int i, vector<vector<int>>& m)   {
            int ai = i;
            for (int aj = 0; aj < m[0].size(); aj++)
                m[ai][aj] = 0;
        }
        
        void fillZero (int i, int j, vector<vector<int>>& m)   {
            fillColZero (j, m);
            fillRowZero (i, m);
        }

        void method1 (vector<vector<int>>& matrix) {
            int n = matrix.size();
            int m = matrix[0].size();

            vector<vector<int>> zlst;
            vector<vector<int>>& mat = matrix;
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    if (mat[i][j] == 0)
                        zlst.push_back ({i, j});

            for(auto p : zlst)
                fillZero (p[0], p[1], mat);
        }

        void method2 (vector<vector<int>>& matrix) {
            int n = matrix.size();
            int m = matrix[0].size();

            vector<int> rows(n, 0);
            vector<int> cols(m, 0);
            vector<vector<int>>& mat = matrix;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (mat[i][j] == 0)
                    {
                        rows[i] = 1;
                        cols[j] = 1;
                    }
                }
            }
            for (int i = 0; i < n; i++)
                if (rows[i] == 1)
                    fillRowZero (i, mat);
            for (int i = 0; i < m; i++)
                if (cols[i] == 1)
                    fillColZero (i, mat);
        }
        
    public:
        void setZeroes(vector<vector<int>>& matrix) {
            method2 (matrix);
        }
    };
}

int leetcode_73_main(int argc, char** argv)
{
    fprintf (stderr, "int leetcode_73_main()\n");
    Solution s1;

    vector<vector<int>> mat1 = {{1,1,1},{1,0,1},{1,1,1}};
    vector<vector<int>> mat2 = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    s1.setZeroes(mat1);
     s1.setZeroes(mat2);

    utils::dump_vectors  ("Example1", mat1);
    utils::dump_vectors  ("Example2", mat2);

    return 0;
}
