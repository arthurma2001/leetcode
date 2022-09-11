/*
  56. Merge Intervals
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

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
        bool inside (int a, int b, int x)
        {
            return x >= a && x <= b;
        }
        bool overlap (int a, int b, int a1, int b1)
        {
            return inside (a, b, a1) || inside (a, b, b1);
        }
        
        vector<vector<int>> method1 (const vector<vector<int>>& intervals0) {
            vector<vector<int>> tmp_lst;
            vector<vector<int>> olst;
            vector<vector<int>> intervals = intervals0;

            while (! intervals.empty())
            {
                int n = intervals.size();
                int a = intervals[0][0];
                int b = intervals[0][1];
                for (int i = 1; i < n; i++)
                {
                    int a1 = intervals[i][0];
                    int b1 = intervals[i][1];
                    if (overlap (a1, b1, a, b))   {   a = min (a, a1);   b = max (b1, b);  }
                    else tmp_lst.push_back (intervals[i]);
                }
                olst.push_back ({ a, b });
                intervals = tmp_lst;
                tmp_lst.clear();
            }
            return olst;
        }

        vector<vector<int>> method2 (const vector<vector<int>>& intervals0) {
            vector<vector<int>> olst;
            vector<vector<int>> intervals = intervals0;
            std::sort (intervals.begin(), intervals.end(),
                       [](const vector<int> &a, vector<int> &b)   {
                           return a[0] < b[0];
                       });
            //utils::dump_vectors ("sorted intervals", intervals);

            int n = intervals.size();
            int a = intervals[0][0];
            int b = intervals[0][1];
            for (int i = 1; i < n; i++)
            {
                int a1 = intervals[i][0];
                int b1 = intervals[i][1];
                if (overlap (a1, b1, a, b))   {   a = min (a, a1);   b = max (b1, b);  }
                else {
                    olst.push_back ({a, b});
                    a = a1, b = b1;
                }
            }
            olst.push_back ({a, b});
            return olst;
        }
        
    public:
        vector<vector<int>> merge(const vector<vector<int>>& intervals) {
            return method2 (intervals);
        }
    };
}

int leetcode_56_main(int argc, char** argv)
{
    fprintf (stderr, "int leetcode_56_main()\n");
    Solution s1;

    vector<vector<int>> out_val1 = s1.merge( {{1,3},{2,6},{8,10},{15,18}});
    vector<vector<int>> out_val2 = s1.merge( {{1,4},{4,5}} );

    utils::dump_vectors  ("Example1", out_val1);
    utils::dump_vectors  ("Example2", out_val2);

    return 0;
}
