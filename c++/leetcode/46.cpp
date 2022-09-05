/*
  46. Permutations
Medium

Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]

Example 3:

Input: nums = [1]
Output: [[1]]
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
// Function to find all permutations of a given string str[i…n-1]
// containing all distinct characters
    void sample_permutations_01 (string str, int i, int n)
    {
        // base condition
        if (i == n - 1)
        {
            cout << str << endl;
            return;
        }
 
        // process each character of the remaining string
        for (int j = i; j < n; j++)
        {
            // swap character at index `i` with the current character
            swap(str[i], str[j]);        // STL `swap()` used
 
            // recur for substring `str[i+1, n-1]`
            sample_permutations_01(str, i + 1, n);
 
            // backtrack (restore the string to its original state)
            swap(str[i], str[j]);
        }
    }
        // Function to find all permutations of a given string
// containing all distinct characters
        void sample_permutations_02 (string str, int n, string result)
{
    // base condition (only one character is left in the string)
    if (n == 1)
    {
        cout << result + str << endl;
        return;
    }
 
    // process each character of the remaining string
    for (int i = 0; i < n; i++)
    {
        // push the current character into the output string and recur
        // for the remaining characters
        sample_permutations_02 (str.substr(1), n - 1, result + str[0]);
 
        // left-rotate the string by 1 unit for the next iteration
        // (use a reverse iterator to right-rotate the string)
        rotate(str.begin(), str.begin() + 1, str.end());
    }
}
        void perm_01 (vector<int> nums, int i, int n,  vector<vector<int>> &out)
        {
            if (i == n-1)
            {
                out.push_back (nums);
                return;
            }
            for (int j = i; j < n; j++)
            {
                swap (nums[i], nums[j]);
                perm_01 (nums, i+1, n, out);
                swap (nums[i], nums[j]);
            }                
        }

        
        vector<vector<int>> method1 (const vector<int>& nums0) {
            vector<int> nums = nums0;
            vector<vector<int>> olst;
            int n = nums.size();

            perm_01 (nums, 0, n, olst);
            return olst;
        }

        void perm_02 (const vector<int> &nums, int i, int n,
                      vector<int> out_item,
                      vector<bool> &used_flgs,
                      vector<vector<int>> &out)
        {
            if (i == n)
            {
                out.push_back (out_item);
                return;
            }

            for (int k = 0; k < n; k++)
            {
                if (! used_flgs[k])
                {
                    used_flgs[k] = true;
                    out_item.push_back (nums[k]);

                    perm_02 (nums, i+1, n, out_item, used_flgs, out);

                    out_item.pop_back();
                    used_flgs[k] = false;
                }
            }
        }

        vector<vector<int>> method2 (const vector<int>& nums0) {
            vector<int> nums = nums0;
            vector<vector<int>> olst;

            int n = nums.size();
            vector<int> out_item;
            vector<bool> used_flgs (n, false);
            std::fill (used_flgs.begin(), used_flgs.end(), false);
            
            perm_02 (nums, 0, n, out_item, used_flgs, olst);
            return olst;
        }

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
                        flgs[k] = true;
                        item_out.push_back (nums[k]);
                        processPerm (nums, i+1, n, flgs, item_out, out);
                        item_out.pop_back();
                        flgs[k] = false;
                    }
                }
            }

        
        vector<vector<int>> method3 (const vector<int>& nums) {
            int n = nums.size();
            vector<int> item_out;
            vector<vector<int>> olst;
            vector<bool> flgs (n, false);
            processPerm (nums, 0, n, flgs, item_out, olst);
            return olst;
        }
        
    public:
        vector<vector<int>> permute (const vector<int>& nums) {
            vector<vector<int>> olst = method3 (nums);
            return olst;
        }
    };    
}

int leetcode_46_main(int argc, char** argv)
{
    fprintf (stderr, "int leetcode_46_main()\n");
    Solution s1;
    vector<vector<int>> out_val1 = s1.permute ({1, 2, 3});
    vector<vector<int>> out_val2 = s1.permute ({0, 1});
    vector<vector<int>> out_val3 = s1.permute ({1});
    
    utils::dump_vectors  ("Example1", out_val1);
    utils::dump_vectors  ("Example2", out_val2);
    utils::dump_vectors  ("Example3", out_val3);

    return 0;
}
