/*
23. Merge k Sorted Lists
Hard

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6

Example 2:

Input: lists = []
Output: []

Example 3:

Input: lists = [[]]
Output: []
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
        ListNode* mergeList (ListNode* list1, ListNode* list2) {
            if (list1 == NULL) return list2;
            if (list2 == NULL) return list1;
            
            if (list1->val < list2->val)
            {
                list1->next = mergeList (list1->next, list2);
                return list1;
            }
            list2->next = mergeList (list1, list2->next);
            return list2;
        }

        ListNode* method1 (vector<ListNode*>& lists) {
            if (lists.empty())
                return NULL;
            
            int n = lists.size();
            ListNode *list1 = lists[0];
            for (int i = 1; i < n; i++)
            {
                list1 = mergeList (list1, lists[i]);
            }
            return list1;
        }

        ListNode* method2 (vector<ListNode*>& lists) {
            if (lists.empty())
                return NULL;
            if (lists.size() == 1)
                return lists[0];

            int n = lists.size();
            int num = n / 2;

            vector<ListNode*> list1;
            copy(lists.begin(), lists.begin() + num, back_inserter(list1));

            vector<ListNode*> list2;
            copy(lists.begin() + num, lists.end(), back_inserter(list2));

            ListNode *left = method2 (list1);
            ListNode *right = method2 (list2);
            ListNode *result = mergeList (left, right);
            return result;
        }
        
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            return method2 (lists);
        }
    };
}

int leetcode_23_main(int argc, char** argv)
{
    fprintf (stderr, "int leetcode_23_main()\n");
    Solution s1;
    vector<ListNode*> in_val1 = createLists({{1,4,5},{1,3,4},{2,6}});
    ListNode* out_val1 = s1.mergeKLists(in_val1);

    vector<ListNode*> in_val2;
    ListNode* out_val2 = s1.mergeKLists(in_val2);
    
    vector<ListNode*> in_val3 = createLists({{}});
    ListNode* out_val3 = s1.mergeKLists(in_val3);
    
    dumpList  ("Example1", out_val1);
    dumpList  ("Example2", out_val2);
    dumpList  ("Example3", out_val3);

    return 0;
}
