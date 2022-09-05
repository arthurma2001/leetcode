/*
20. Valid Parentheses
Easy

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
    Every close bracket has a corresponding open bracket of the same type.

 

Example 1:

Input: s = "()"
Output: true

Example 2:

Input: s = "()[]{}"
Output: true

Example 3:

Input: s = "(]"
Output: false

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
using namespace leetcode;

namespace
{
    class Solution {
        
        //Input: s = "()[]{}"
        bool method1 (string s)
        {
            int cnt_i = 0; // (
            int cnt_j = 0; // [
            int cnt_k = 0; // {

            int n = s.length();
            for (int i = 0; i < n; i++)
            {
                char ch = s[i];
                switch (ch)
                {
                case '(':
                    cnt_i ++;
                    break;
                case ')':
                    if (i != 0 && s[i-1] == '(')
                        cnt_i --;
                    break;
                case '[':
                    cnt_j ++;
                    break;
                case ']':
                    if (i != 0 && s[i-1] == '[')
                        cnt_j --;
                    break;
                case '{':
                    cnt_k ++;
                    break;
                case '}':
                    if (i != 0 && s[i-1] == '}')
                        cnt_k --;
                    break;
                default:
                    return false;
                }
            }
            return cnt_i == 0 && cnt_j == 0 && cnt_k == 0;
        }
        
        bool method2 (string s)
        {
            std::stack<char> S;
            int n = s.length();
            for (int i = 0; i < n; i++)
            {
                char ch = s[i];
                if (ch == '(' || ch == '[' || (ch == '{'))
                    S.push (ch);
                else if (!S.empty() &&
                         (  (ch == ')' && S.top() == '(') ||
                            (ch == ']' && S.top() == '[') ||
                            (ch == '}' && S.top() == '{')))
                {
                    S.pop();
                    break;
                }
                else
                    return false;
            }
            return S.empty();
        }
        
    public:
        bool isValid(string s) {
            return method2 (s);
        }
    };
}

int leetcode_20_main(int argc, char** argv)
{
    fprintf (stderr, "int leetcode_20_main()\n");
    Solution s1;
    bool out_val1 = s1.isValid("()");
    bool out_val2 = s1.isValid("()[]{}");
    bool out_val3 = s1.isValid("(]");

    utils::dumpBool  ("Example1", out_val1);
    utils::dumpBool  ("Example2", out_val2);
    utils::dumpBool  ("Example3", out_val3);

    return 0;
}
