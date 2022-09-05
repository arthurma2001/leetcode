/*
21. Merge Two Sorted Lists

Easy
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:

Input: list1 = [], list2 = []
Output: []

Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
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
        ListNode* method1(ListNode* list1, ListNode* list2) {
            if (list1 == NULL) return list2;
            if (list2 == NULL) return list1;
            
            ListNode *p1 = list1;
            ListNode *p2 = list2;
            ListNode *head = NULL, *curr = NULL;
            while (p1 && p2)
            {
                ListNode *p = NULL;
                if (p1->val < p2->val)
                {
                    p = p1;  p1 = p1->next;
                }
                else
                {
                    p = p2;  p2 = p2->next;
                }
                if (! head)
                {
                    head = p;
                    curr = p;
                }
                else
                {
                    curr->next = p;
                    curr = p;
                }
            }
            if  (p1)
                curr->next = p1;
            if (p2)
                curr->next = p2;
                
            return head;
        }

        ListNode* method2 (ListNode* list1, ListNode* list2) {
            if (list1 == NULL) return list2;
            if (list2 == NULL) return list1;
            
            if (list1->val < list2->val)
            {
                list1->next = method2 (list1->next, list2);
                return list1;
            }
            list2->next = method2 (list1, list2->next);
            return list2;
        }
        
    public:
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            //return method1 (list1, list2);
            return method2 (list1, list2);
        }
    };
}

int leetcode_21_main(int argc, char** argv)
{
    fprintf (stderr, "int leetcode_21_main()\n");
    Solution s1;
    ListNode* out_val1 = s1.mergeTwoLists(createList({1,2,4}), createList({1,3,4}));
    ListNode* out_val2 = s1.mergeTwoLists(createList({}), createList({}));
    ListNode* out_val3 = s1.mergeTwoLists(createList({}), createList({0}));
    
    dumpList  ("Example1", out_val1);
    dumpList  ("Example2", out_val2);
    dumpList  ("Example3", out_val3);

    return 0;
}
