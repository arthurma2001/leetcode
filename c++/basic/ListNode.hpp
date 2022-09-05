#ifndef __ListNode_hpp__
#define __ListNode_hpp__
#include <vector>
#include <string>
using namespace std;

namespace basic
{
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    void freeList (ListNode *head);
    ListNode *createList (const vector<int> &vals);
    vector<ListNode*> createLists (const vector<vector<int>> &val_lists);
    void dumpList (const string &title, ListNode *head);
}

#endif
