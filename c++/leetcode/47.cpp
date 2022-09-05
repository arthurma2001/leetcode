/*
  47. Permutations II
Medium

Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

 

Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]

Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
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
    class Solution
    {
        void processPerm (const vector<int>& nums, int i, int n,
                          vector<bool> &flgs,
                          vector<int> item_out,
                          vector<vector<int>> &out)
            {
                if (i == n)
                {
                    out.push_back (item_out);
                    return;
                }

                for (int k = 0; k < n; k++)
                {
                    if (! flgs[k])
                    {
                        if (k > 0 && nums[k-1] == nums[k] && ! flgs[k-1])
                            continue;
                        flgs[k] = true;
                        item_out.push_back (nums[k]);
                        processPerm (nums, i+1, n, flgs, item_out, out);
                        item_out.pop_back();
                        flgs[k] = false;
                    }
                }
            }

        vector<vector<int>> method3 (const vector<int>& nums0) {
            vector<int> nums = nums0;
            sort (nums.begin(), nums.end());
            
            int n = nums.size();
            vector<int> item_out;
            vector<vector<int>> olst;
            vector<bool> flgs (n, false);
            processPerm (nums, 0, n, flgs, item_out, olst);
            return olst;
        }
        
    public:
        vector<vector<int>> permuteUnique (const vector<int>& nums0) {
            return method3 (nums0);
        }
    };    
}

int leetcode_47_main(int argc, char** argv)
{
    fprintf (stderr, "int leetcode_47_main()\n");
    Solution s1;
    vector<vector<int>> out_val1 = s1.permuteUnique ({1, 1, 2});
    vector<vector<int>> out_val2 = s1.permuteUnique ({1, 2, 3});
    
    utils::dump_vectors  ("Example1", out_val1);
    utils::dump_vectors  ("Example2", out_val2);

    return 0;
}
