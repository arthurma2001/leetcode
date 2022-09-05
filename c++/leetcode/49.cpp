/*
49. Group Anagrams
Medium

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Example 2:

Input: strs = [""]
Output: [[""]]

Example 3:

Input: strs = ["a"]
Output: [["a"]]
**/

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <tuple>
#include <stack>
#include <algorithm>
#include <functional>
using namespace std;
#include "basic/utils.hpp"
#include "basic/ListNode.hpp"
using namespace leetcode;
using namespace basic;

namespace
{
    class Solution {
        bool isAnagrams (const string &a, const string &b)
         {
             if (a.length() != b.length())
                 return false;
             
             std::map<char, char> m;
             for (auto c : a)
                 m[c] = c;
             for (auto c : b)
                 if (m.find (c) == m.end())
                     return false;
             return true;
         }
                
        vector<vector<string>> method1(const vector<string>& strs0) {
            vector<vector<string>>  olst;
            
            vector<string> strs = strs0;
            while (! strs.empty())
            {
                vector<int> indexes;
                string w1 = strs[0];
                indexes.push_back(0);
                for (int i = 1; i < strs.size(); i++)
                {
                    if (isAnagrams (w1, strs[i]))
                        indexes.push_back (i);
                }
                
                vector<string> xlst;
                for (auto i : indexes)
                    xlst.push_back (strs[i]);
                olst.push_back (xlst);
                
                std::reverse (indexes.begin(), indexes.end());
                for (auto i : indexes)
                    strs.erase (strs.begin() + i);
            }
            return olst;
        }

        void sortString (string &str)
        {
            sort(str.begin(), str.end());
            //cout << str;
        }
        
        vector<vector<string>> method2(const vector<string>& strs) {
            vector<vector<string>>  olst;
            std::map<string, vector<string>> amap;

            int n =  strs.size();
            for (int i = 0; i < n; i++)
            {
                string w = strs[i];
                sortString (w);

                if (amap.find (w) == amap.end())
                    amap[w] = { strs[i] };
                else
                    amap[w].push_back (strs[i]);
            }

            for (auto [k, v] : amap)
            {
                olst.push_back (v);
            }
            return olst;
        }
        
    public:
        vector<vector<string>> groupAnagrams(const vector<string>& strs) {
            vector<vector<string>>  olst = method2 (strs);
            return olst;
        }
    };
}

int leetcode_49_main(int argc, char** argv)
{
    fprintf (stderr, "int leetcode_49_main()\n");
    Solution s1;
    
    vector<vector<string>> out_val1 =
        s1.groupAnagrams  ({"eat","tea","tan","ate","nat","bat"});
    vector<vector<string>> out_val2 =  s1.groupAnagrams  ({""});
    vector<vector<string>> out_val3 =  s1.groupAnagrams  ({"a"});
    
    utils::dump_vectors  ("Example1", out_val1);
    utils::dump_vectors  ("Example2", out_val2);
    utils::dump_vectors  ("Example3", out_val3);

    return 0;
}
