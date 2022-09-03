/**
1. Two Sum
Easy

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
*/
#include <iostream>
#include <vector>
#include <map>
using namespace std;
#include "basic/utils.hpp"

namespace
{
    class Solution {
    public:
        vector<int> twoSum(const vector<int>& nums, int target) {
            vector<int> out_vals;
            std::map<int, int> m;
            
            int n = nums.size();
            for (int i = 0; i < n; i++)
            {
                int v  = nums[i];
                if (m.find (target - v) != m.end())
                {
                    out_vals = {m[target-v], i};
                    break;
                }
                m[v] = i;
            }
            return out_vals;
        }
    };
}

int leetcode_1_main(int argc, char** argv)
{
    Solution s1;
    vector<int> out_val1 = s1.twoSum({2,7,11,15},  9);
    vector<int> out_val2 = s1.twoSum({3,2,4}, 6);
    vector<int> out_val3 = s1.twoSum({3,3}, 6);

    leetcode::utils::dump_vector ("Example1", out_val1);
    leetcode::utils::dump_vector ("Example2", out_val2);
    leetcode::utils::dump_vector ("Example3", out_val3);
    return 0;
}
