/*
15. 3Sum
Medium

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.

Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.

Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.

 

Constraints:

    3 <= nums.length <= 3000
    -105 <= nums[i] <= 105

**/

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <tuple>
#include <algorithm>
using namespace std;
#include "basic/utils.hpp"

namespace
{
    class Solution {
        typedef std::array<int, 3> D;
        struct Cmp
        {
            bool operator () (const D &i1, const D &i2)
                {
                    std::set<int> a ({ i1[0], i1[1], i1[2] });
                    std::set<int> b ({ i2[0], i2[1], i2[2] });
                    return a < b;
                }
        };

        vector<vector<int>> method1 (const vector<int>& nums)
         {
            set<D, Cmp> out_r;
            int n = nums.size();
            for (int i = 0; i < n-2; i++)
            {
                int a = nums[i];
                for (int j = i+1; j < n-1; j++)
                {
                    int b = nums[j];
                    for (int k = j+1; k < n; k++)
                    {
                        int c = nums[k];
                        if ((a + b + c) == 0)
                        {
                            auto alst = D ({a, b, c});
                            out_r.insert (alst);
                        }
                    }
                }
            }
            vector<vector<int>> out_r2;
            for (auto vlst : out_r)
            {
                vector<int> rlst({vlst[0], vlst[1], vlst[2]});
                out_r2.push_back (rlst);
            }
            return out_r2;
        }

        vector<vector<int>> method2 (const vector<int>& nums0)
         {
             set<D, Cmp> out_r;
            vector<vector<int>> out_r2;

            vector<int> nums = nums0;
             std::sort(nums.begin(), nums.end());

             int n = nums.size();
             if (nums[0] > 0)
                 return out_r2;
             if (nums[n-1] < 0)
                 return out_r2;

             int left = 0;
             int max_neg = - nums[0];
             for (int i = 0; i < n-2; i++)
             {
                int a = nums[i];
                if (a > max_neg)
                    break;
                
                for (int j = i+1; j < n-1; j++)
                {
                    int b = nums[j];
                    if (b > max_neg)
                        break;
                    for (int k = j+1; k < n; k++)
                    {
                        int c = nums[k];
                        if (c > max_neg)
                            break;
                        if ((a + b + c) == 0)
                        {
                            auto alst = D ({a, b, c});
                            out_r.insert (alst);
                        }
                    }
                }
            }

            for (auto vlst : out_r)
            {
                vector<int> rlst({vlst[0], vlst[1], vlst[2]});
                out_r2.push_back (rlst);
            }
            return out_r2;
        }

        // not working
        vector<vector<int>> method3 (const vector<int>& nums0)
         {
             set<D, Cmp> out_r;
            vector<vector<int>> out_r2;

            vector<int> nums = nums0;
             std::sort(nums.begin(), nums.end());

             int n = nums.size();
             if (nums[0] > 0)
                 return out_r2;
             if (nums[n-1] < 0)
                 return out_r2;

             int left = 0;
             std::map<int, vector<int>> lookupDic;
             for (int i = 0; i < n; i++)
             {
                int a = nums[i];
                if (lookupDic.find(a) != lookupDic.end())
                    lookupDic[a].push_back (i);
                else
                {
                    std::vector<int> alst ({i});
                    lookupDic.insert (std::pair<int,vector<int>>(a, alst));
                }
             }
             
             int max_neg = - nums[0];
             for (int i = 0; i < n; i++)
             {
                if (nums[i] > max_neg)
                    break;

                if (i != 0 && nums[i] == nums[i-1])
                    continue;

                int a = nums[i];
                int twoSum = - nums[i];
                for (int j = i+1; j < n; j++)
                {
                    int b = nums[j];
                    if (b > max_neg)
                        break;
                    
                    int target = twoSum - b;
                    if (lookupDic.find (target) != lookupDic.end())
                    {
                        int n1 = lookupDic[target].size();
                        int cnt = 1;
                        if (target == a) cnt ++;
                        if (target == b) cnt++;
                        if (n1 < cnt)
                            continue;

                        if (n1 > 0)
                        {
                            int c = target;
                            lookupDic[target].pop_back();
                            auto alst = D ({a, b, c});
                            out_r.insert (alst);
                            fprintf (stderr, "alst=(%d,%d,%d), target=%d, lookupDic size=%d\n", a, b, c, target, lookupDic[target].size());
                        }
                    }
                }
            }

            for (auto vlst : out_r)
            {
                vector<int> rlst({vlst[0], vlst[1], vlst[2]});
                out_r2.push_back (rlst);
            }
            return out_r2;
        }
        
    public:
        vector<vector<int>> threeSum(const vector<int>& nums) {
            return method3 (nums);
        }
    };
}

int leetcode_15_main(int argc, char** argv)
{
    Solution s1;
    vector<vector<int>> out_val1 = s1.threeSum({-1,0,1,2,-1,-4});
    vector<vector<int>> out_val2 = s1.threeSum({0,1,1});
    vector<vector<int>> out_val3 = s1.threeSum({0,0,0});

    leetcode::utils::dump_vectors ("Example1", out_val1);
    leetcode::utils::dump_vectors ("Example2", out_val2);
    leetcode::utils::dump_vectors ("Example3", out_val3);
    return 0;
}
