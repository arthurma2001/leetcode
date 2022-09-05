/*
  39. Combination Sum
Medium

Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

 

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.

Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]

Example 3:

Input: candidates = [2], target = 1
Output: []
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
        
        void findPermSum  (const vector<int> &nums, int target,
                           int i, int n,
                           vector<int> out_item,
                           vector<vector<int>> &out)
        {
            if (target <= 0)
            {
                if (target == 0)
                    out.push_back (out_item);
                return;
            }

            for (int k = i; k < n; k++)
            {
                out_item.push_back (nums[k]);
                findPermSum  (nums, target - nums[k],
                              k, n, out_item,  out);
                out_item.pop_back();
            }
        }

        vector<vector<int>> method1  (const vector<int>& nums0, int target) {
            vector<int> nums = nums0;
            vector<vector<int>> olst;

            int n = nums.size();
            vector<int> out_item;
            
            findPermSum  (nums, target, 0, n, out_item, olst);
            return olst;
        }

        void ama_findPermSum  (const vector<int>& nums, int target,
                               int index, int n, vector<int> out_item, 
                               vector<vector<int>> &out)
         {
             if (target <= 0)
             {
                 if (target == 0)
                     out.push_back (out_item);
                 return;
             }

             for (int i = index; i < n; i++)
             {
                 out_item.push_back (nums[i]);
                 ama_findPermSum (nums, target-nums[i],
                                  index, n, out_item, out);
                 out_item.pop_back();
             }
         }

        vector<vector<int>> ama_method1  (const vector<int>& nums0, int target) {
            vector<int> nums = nums0;
            vector<vector<int>> olst;

            int n = nums.size();
            vector<int> out_item;
            
            ama_findPermSum  (nums, target, 0, n, out_item, olst);
            return olst;
        }
        
    public:
        vector<vector<int>> combinationSum(const vector<int>& candidates, int target) {
            vector<vector<int>> olst = ama_method1 (candidates, target);
            return olst;
        }
    };    
}

int leetcode_39_main(int argc, char** argv)
{
    fprintf (stderr, "int leetcode_39_main()\n");
    Solution s1;
    vector<vector<int>> out_val1 = s1.combinationSum ({2,3,6,7}, 7);
    vector<vector<int>> out_val2 = s1.combinationSum ({2,3,5}, 8);
    vector<vector<int>> out_val3 = s1.combinationSum ({2}, 1);
    
    utils::dump_vectors  ("Example1", out_val1);
    utils::dump_vectors  ("Example2", out_val2);
    utils::dump_vectors  ("Example3", out_val3);

    return 0;
}
