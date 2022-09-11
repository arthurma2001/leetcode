/*
  62. Unique Paths
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.
Input: m = 3, n = 7
Output: 28

Example 2:

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down

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
        int method1 (int m, int n) {
            vector<int> zeros (m, 0);
            vector< vector <int> > dp(n, zeros);
            for (int i = 0; i < m; i++)
                dp[0][i] = 1;
            for (int i = 0; i < n; i++)
                dp[i][0] = 1;

            for (int i = 1; i < n; i++) {
                for (int j = 1; j < m; j++)
                {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
            return dp[n-1][m-1];
        }
        
    public:
        /** m --> col, n --> row */
        int uniquePaths(int m, int n) {
            return method1 (m, n);
        }
    };
}

int leetcode_62_main(int argc, char** argv)
{
    fprintf (stderr, "int leetcode_62_main()\n");
    Solution s1;

    int out_val1 = s1.uniquePaths(3, 7);
    int out_val2 = s1.uniquePaths(3, 2);

    utils::dump_val  ("Example1", out_val1);
    utils::dump_val  ("Example2", out_val2);

    return 0;
}
