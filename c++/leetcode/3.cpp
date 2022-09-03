/**
3. Longest Substring Without Repeating Characters
Medium

Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
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
        int lengthOfLongestSubstring(const string &s) {
            return answer2 (s);
        }
    protected:
        int answer1 (const string &s)
        {
            std::map<char, int> m;
            int left = 0;
            int right = 0;
            int result = 0;

            int n = s.length();
            while (right < n)
            {
                char ch = s[right];
                if (m.find (ch) != m.end())
                {
                    left = m[ch];
                    left ++;
                }
                m[ch] = right;
                right ++;
                result = max (result, right - left);
            }
            return result;
        }

        int answer2 (const string &s)
        {
            std::array<int, 256> m;
            std::fill (m.begin(), m.end(), -1);
            
            int left = 0;
            int right = 0;
            int result = 0;

            int n = s.length();
            while (right < n)
            {
                char ch = s[right];
                if (m[ch] != -1)
                {
                    left = m[ch];
                    left ++;
                }
                m[ch] = right;
                right ++;
                result = max (result, right - left);
            }
            return result;
        }
        
    };
}

int leetcode_3_main(int argc, char** argv)
{
    Solution s1;
    int out_val1 = s1.lengthOfLongestSubstring("abcabcbb");
    int out_val2 = s1.lengthOfLongestSubstring("bbbbb");
    int out_val3 = s1.lengthOfLongestSubstring("pwwkew");

    leetcode::utils::dump_vector<int> ("Example1", { out_val1});
    leetcode::utils::dump_vector<int> ("Example2", { out_val2});
    leetcode::utils::dump_vector<int> ("Example3", { out_val3});
    return 0;
}
