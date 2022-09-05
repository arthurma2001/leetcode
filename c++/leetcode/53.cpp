/*
  53. Maximum Subarray
Medium

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

Example 2:

Input: nums = [1]
Output: 1

Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23

**/

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <tuple>
#include <stack>
#include <algorithm>
#include <functional>
#include <bits/stdc++.h>
using namespace std;
#include "basic/utils.hpp"
#include "basic/ListNode.hpp"
using namespace leetcode;
using namespace basic;

namespace
{
    class Solution {
        int helper(int i,int j, vector<int>& nums)
            {
                if(i==j) return nums[i];
                int left_cross=INT_MIN, right_cross=INT_MIN;
                int mid= (i+j)/2;
                int cur=0;
                for(int k=mid+1;k<=j;k++)
                {
                    cur+= nums[k];
                    right_cross= max(right_cross,cur);
                }
                cur=0;
                for(int k=mid;k>=i;k--)
                {
                    cur+= nums[k];
                    left_cross= max(left_cross,cur);
                }
                int cross_sum = left_cross + right_cross;
                int left_sum  = helper(i,mid,nums);
                int right_sum = helper(mid+1,j,nums);
                return max( cross_sum , max(left_sum , right_sum) );
            }
        int sample_maxSubArray(vector<int>& nums) {
            return helper(0,nums.size()-1,nums);
        }

        int recurSum (int i, int j, vector<int>& nums)
        {
            if (i == j) return nums[i];
            int mid = (i+j)/2;

            int cur = 0;
            int left_s1 = INT_MIN;
            for (int  k = mid; k >= i; k--)
            {
                cur += nums[k];
                left_s1 = max (left_s1, cur);
            }

            cur = 0;
            int right_sl = INT_MIN;
            for (int  k=mid+1; k <= j; k++)
            {
                cur += nums[k];
                right_sl = max (right_sl, cur);
            }

            int max_val = left_s1 + right_sl;
            int left_max = recurSum (i, mid, nums);
            int right_max = recurSum (mid+1, j, nums);
            
            return max(max_val, max(left_max, right_max));
        }
        
        int method1 (vector<int>& nums) {
            return recurSum(0,nums.size()-1,nums);
        }

        int method2 (vector<int>& nums) {
            if (nums.size() == 0)
                return 0;
            if (nums.size() == 1) return nums[0];

            int n = nums.size();
            vector<int> dp (n, 0);

            dp[0] = nums[0];
            int max_val = INT_MIN;
            for (int i = 1; i < n; i++)
            {
                if (dp[i-1] > 0)
                    dp[i] = dp[i-1]+nums[i];
                else
                    dp[i] = nums[i];
                max_val = max (dp[i], max_val);
            }
            return max_val;
        }

        int method3 (vector<int>& nums)  {
            if (nums.size() == 0)
                return 0;
            if (nums.size() == 1) return nums[0];

            int n = nums.size();
            int maxSum = nums[0], res = 0;
            for (int i = 0; i < n; i++) {
                res += nums[i];
                if (res > maxSum)
                    maxSum = res;
                if (res < 0) res = 0;
            }
            return maxSum;
        }
                
    public:
        int maxSubArray(const vector<int>& nums0) {
            vector<int> nums = nums0;
            //return sample_maxSubArray (nums);
            return method3 (nums);
        }
    };
}

int leetcode_53_main(int argc, char** argv)
{
    fprintf (stderr, "int leetcode_53_main()\n");
    Solution s1;
    int out_val1 = s1.maxSubArray({-2,1,-3,4,-1,2,1,-5,4});
    int out_val2 = s1.maxSubArray({1});
    int out_val3 = s1.maxSubArray({5,4,-1,7,8});
    int out_val4 = s1.maxSubArray({-5,-4,-1,2, -2,0, 1});
    
    utils::dump_val  ("Example1", out_val1);
    utils::dump_val  ("Example2", out_val2);
    utils::dump_val  ("Example3", out_val3);
    utils::dump_val  ("Example4", out_val4);

    return 0;
}
