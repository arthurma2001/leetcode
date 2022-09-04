/*
  22. Generate Parentheses
  
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:

Input: n = 1
Output: ["()"]

Constraints:
    1 <= n <= 8

**/

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <tuple>
#include <algorithm>
using namespace std;
#include "basic/utils.hpp"

/**
   Analysis
      n == 1 ()
      n == 2 ()(), --> (())
      n == 3 ()()(), ((())),  --> (()()) ()(()) (())()
**/

namespace
{
    class Solution {
        void generate (int n, vector<string> &olst, string s, int left, int right)
        {
            if (left == n && right == n)
            {
                olst.push_back (s);
                return;
            }
            if (left < n)
                generate (n, olst, s + "(", left +1, right);
            if (right < left)
                generate (n, olst, s + ")", left, right+1);
        }
        
    public:
        vector<string> generateParenthesis(int n) {
            string s;
            vector<string> olst;
            generate (n, olst, s, 0, 0);
            return olst;
        }
    };
}

int leetcode_22_main(int argc, char** argv)
{
    Solution s1;
    vector<string> out_val1 = s1.generateParenthesis(3);
    vector<string> out_val2 = s1.generateParenthesis(1);

    leetcode::utils::dump_vector ("Example1", out_val1);
    leetcode::utils::dump_vector ("Example2", out_val2);
    return 0;
}
