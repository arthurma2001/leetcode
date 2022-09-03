/**
   11. Container With Most Water
   You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.
*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#include "basic/utils.hpp"

namespace
{
    class Solution {
        int method1 (const vector<int>& height)
        {
            //vector<int> height1 = height;
            //std::sort (height1.begin(), height1.end());
            int maxA = 0;
            int n = height.size();
            for (int i = 0; i < n; i++)
            {
                int a = height[i];
                for (int j = i; j < n; j++)
                {
                    int b = height[j];
                    int s = (j-i) * min(a,b);
                    maxA = max (maxA, s);
                }
            }
            return maxA;
        }

        int method2 (const vector<int>& height)
        {
            struct D
            {
                D (int i, int h) { this->h = h; this->i = i; }
                int i, h;
            };

            vector<D> dlst;
            int n = height.size();
            for (int i = 0; i < n; i++)
            {
                dlst.push_back (D(i, height[i]));
            }
            
            auto cmp_func = [](const D& a, const D&b) -> bool { return a.h > b.h; };
            std::sort (dlst.begin(), dlst.end(), cmp_func);
            // for (auto d : dlst)  {  fprintf (stderr, "    (%d,%d)\n", d.i, d.h);  }
            
            int maxA = 0;
            for (int left = 0; left < n; left++)
            {
                int a = dlst[left].h;
                int i = dlst[left].i;
                
                for (int right = left+1; right < n; right++)
                {
                    int b = dlst[right].h;
                    int j = dlst[right].i;
                    int s = (j-i) * min(a,b);
                    maxA = max (maxA, s);
                }
            }
            return maxA;
        }

        int method3 (const vector<int>& height)
        {
            int maxA = 0;
            int start = 0;
            int end = height.size()-1;
            while (start < end)
            {
                int h;
                int w = end-start;
                if (height[start] < height[end])
                {
                    h = height[start];
                    start++;
                }
                else
                {
                    h = height[end];
                    end--;
                }
                
                int s = w * h;
                maxA = max (maxA, s);
            }
            return maxA;
        }
        
    public:
        int maxArea(const vector<int>& height) {
            return method3 (height);
        }        
    };
}

int leetcode_11_main(int argc, char** argv)
{
    Solution s1;
    int out_val1 = s1.maxArea({1,8,6,2,5,4,8,3,7});
    int out_val2 = s1.maxArea({1, 1});

    leetcode::utils::dump_vector<int> ("Example1", { out_val1});
    leetcode::utils::dump_vector<int> ("Example2", { out_val2});
    return 0;
}
