/*
33. Search in Rotated Sorted Array
Medium

There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Example 3:

Input: nums = [1], target = 0
Output: -1
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

    public:

        //  https://www.geeksforgeeks.org/binary-search/
        int binarySearch(const int *arr, int x, int low, int high)
        {
            if (low > high)
                return -1;
            
            int mid = (low + high)/2;
            if (arr[mid] == x)
                return mid;
            if (x > arr[mid])
                return binarySearch (arr, x, mid+1, high);
            return binarySearch (arr, x, low, mid-1);
        }

        int binarySearch2 (const int *arr, int x, int low, int high)
        {
            while (low <= high)
            {
                int mid = (low + high)/2;
                if (x == arr[mid])
                    return mid;
                if (x > arr[mid]) // x is on the right side
                    low = mid + 1;
                else                  // x is on the left side
                    high = mid - 1;
            }
            return -1;
        }

        // correct answer
        int binarySearch3a (const int *arr, int x, int low, int high)
        {
            while (low <= high)
            {
                int mid = (low + high)/2;
                if (x == arr[mid])
                    return mid;
                if (arr[mid] > arr[low])
                {
                    if (arr[low] <= x && x < arr[mid])
                        high=mid-1;
                    else
                        low=mid+1;
                }
                else if (arr[mid] < arr[high])
                {
                    if (arr[mid] < x && x <= arr[high])
                        low=mid+1;
                    else
                        high=mid-1;
                }
                else
                {
                    if (arr[low] == arr[mid])
                        low ++;
                    if (arr[high] == arr[mid])
                        high --;
                }
            }
            return -1;
        }

        int binarySearch3b (const int *arr, int x, int low, int high)
        {
            while (low <= high)
            {
                int mid = (low + high)/2;
                if (x == arr[mid])
                    return mid;
                if (arr[low] < arr[mid])
                {
                    if (x >= arr[low] && x < arr[mid])
                        high = mid-1;
                    else
                        low = mid+1;
                }
                else if (arr[mid] < arr[high])
                {
                    if (x > arr[mid] && x <= arr[high])
                        low = mid + 1;
                    else
                        high = mid - 1;
                }
                else
                {
                    if (arr[mid] == arr[low]) low ++;
                    if (arr[mid] == arr[high]) high --;
                }
            }
            return -1;
        }
        
        int method1 (const vector<int>& nums, int target) {
            int n = nums.size();
            return binarySearch3b (&nums[0], target, 0, n-1);
        }

    public:
        int search(const vector<int>& nums, int target) {
            return method1 (nums, target);
        }
    };
}

int leetcode_33_main(int argc, char** argv)
{
    fprintf (stderr, "int leetcode_33_main()\n");
    Solution s1;
    int out_val0 = s1.search({0,1,2,4,5,6,7}, 0);
    int out_val1 = s1.search({4,5,6,7,0,1,2}, 0);
    int out_val2 = s1.search({4,5,6,7,0,1,2}, 3);
    int out_val3 = s1.search({1}, 0);
    
    utils::dump_val  ("Example0", out_val0);
    utils::dump_val  ("Example1", out_val1);
    utils::dump_val  ("Example2", out_val2);
    utils::dump_val  ("Example3", out_val3);

    return 0;
}
