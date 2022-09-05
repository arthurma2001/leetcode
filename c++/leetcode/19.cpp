/*
  Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:

Input: head = [1], n = 1
Output: []

Example 3:
Input: head = [1,2], n = 1
Output: [1]

Constraints:
    The number of nodes in the list is sz.
    1 <= sz <= 30
    0 <= Node.val <= 100
    1 <= n <= sz
**/

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <tuple>
#include <algorithm>
using namespace std;
#include "basic/utils.hpp"
#include "basic/ListNode.hpp"
using namespace basic;

namespace
{
    class Solution {
        ListNode* method1(ListNode* head, int n)
        {
            ListNode* phead = head;
            ListNode *fast = phead;
            ListNode *prev = NULL;
            ListNode *curr = NULL;

            int total_node = 0;
            for (int i = 0; fast; i++)
            {
                if (i == n)
                    break;
                fast = fast->next;
                total_node ++;
            }

            if (! fast)
            {
                if (n == total_node)
                {
                    ListNode *q = head->next;
                    delete  head;
                    return q;
                }
                // node doesn't exist
                return head;
            }

            curr = head;
            while (fast)
            {
                prev = curr;
                curr = curr->next;
                fast = fast->next;
            }

            prev->next = curr->next;
            delete curr;
            return phead;
        }
        
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n)
        {
            return method1 (head, n);
        }
    };
}

int leetcode_19_main(int argc, char** argv)
{
    fprintf (stderr, "int leetcode_19_main()\n");
    Solution s1;
    ListNode* out_val1 = s1.removeNthFromEnd(createList({1,2,3,4,5}), 2);
    ListNode* out_val2 = s1.removeNthFromEnd(createList({1}), 1);
    ListNode* out_val3 = s1.removeNthFromEnd(createList({1,2}), 1);
    ListNode* out_val4 = s1.removeNthFromEnd(createList({1,2,3}), 3);

    dumpList  ("Example1", out_val1);
    dumpList  ("Example2", out_val2);
    dumpList  ("Example3", out_val3);
    dumpList  ("Example4", out_val4);

    return 0;
}
