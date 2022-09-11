/*
  57. Insert Interval
You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

 

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
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
        bool insideInterval (int a, int b, int a1, int b1)
        {
            return inside (a, b, a1) && inside (a, b, b1);
        }
        
        bool overlap (int a, int b, int a1, int b1)
        {
            return inside (a, b, a1) || inside (a, b, b1);
        }
        
        vector<vector<int>> method1 (const vector<vector<int>>& intervals,
                                     const vector<int>& newInterval) {
            vector<vector<int>> olst;
            int n = intervals.size();
            int a = newInterval[0];
            int b = newInterval[1];
            const vector<vector<int>>& plst = intervals;

            for (int i = 0; i < n; i++)
            {
                if ( ! overlap (a, b, plst[i][0], plst[i][1]))
                {
                    olst.push_back (plst[i]);
                    continue;
                }
                if (insideInterval (a, b, plst[i][0], plst[i][1]))
                    continue;
                else
                {
                    a = min (a, plst[i][0]);
                    b = max (b, plst[i][1]);
                }
            }
            olst.push_back ({ a, b });
            std::sort (olst.begin(), olst.end(),
                       [](const vector<int> &a, vector<int> &b)   {
                           return a[0] < b[0];
                       });
            return olst;
        }

        vector<vector<int>> method2 (const vector<vector<int>>& intervals,
                                     const vector<int>& newInterval) {
            vector<vector<int>> olst;
            int n = intervals.size();
            int a = newInterval[0];
            int b = newInterval[1];
            const vector<vector<int>>& plst = intervals;

            int inserted_i0 = n;
            bool inserted = false;
            for (int i = 0; i < n; i++)
            {
                if ( !overlap (a, b, plst[i][0], plst[i][1]))
                {
                    if (inserted)
                    {
                        inserted_i0 = i;
                        break;
                    }
                    olst.push_back (plst[i]);
                    continue;
                }
                if (insideInterval (a, b, plst[i][0], plst[i][1]))
                    continue;
                else
                {
                    a = min (a, plst[i][0]);
                    b = max (b, plst[i][1]);
                    inserted = true;
                }
            }
            olst.push_back ({ a, b });
            for (int i = inserted_i0; i < n; i++)
            {
                olst.push_back (plst[i]);
            }
            return olst;
        }
        
    public:
        vector<vector<int>> insert(const vector<vector<int>>& intervals,
                                   const vector<int>& newInterval) {
            return method2 (intervals, newInterval);
        }
    };
}

int leetcode_57_main(int argc, char** argv)
{
    fprintf (stderr, "int leetcode_57_main()\n");
    Solution s1;

    vector<vector<int>> out_val1 = s1.insert( {{1,3},{6,9}},  {2,5});
    vector<vector<int>> out_val2 = s1.insert( {{1,2},{3,5},{6,7},{8,10},{12,16}} ,  {4,8});

    utils::dump_vectors  ("Example1", out_val1);
    utils::dump_vectors  ("Example2", out_val2);

    return 0;
}
