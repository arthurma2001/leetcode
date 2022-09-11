/*
  55. Jump Game
  You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.


Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
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
        bool recursive_method1 (const vector<int>& nums, int i0, int step)
        {
            int i = i0 + step;
            if (i == nums.size()-1)
                return true;

            bool e1 = false;
            int max_step = nums[i];
            for (int k = max_step; k >= 1; k--)
            {
                e1 = recursive_method1 (nums, i, k);
                if (e1 == true)
                    break;
            }
            return e1;
        }
        
        bool method1 (const vector<int>& nums) {
            int sum = nums.size() - 1;
            return recursive_method1 (nums, 0, 0);
        }

        bool method2 (const vector<int>& nums) {
            int n = nums.size();
            if (n <= 1)
                return true;

            int lastPoint = n-1;
            for (int i = n-1; i >= 0; i--)
            {
                if (i + nums[i] >= lastPoint)
                    lastPoint = i;
            }
            return lastPoint == 0;
        }
        
    public:
        bool canJump(const vector<int>& nums) {
            return method1 (nums);;
        }
    };    
}

int leetcode_55_main(int argc, char** argv)
{
    fprintf (stderr, "int leetcode_55_main()\n");
    Solution s1;
    
    bool out_val1 = s1. canJump({2,3,1,1,4});
    bool out_val2 = s1. canJump({3,2,1,0,4});

    utils::dumpBool  ("Example1", out_val1);
    utils::dumpBool  ("Example2", out_val2);

    return 0;
}
