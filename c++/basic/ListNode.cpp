#include "ListNode.hpp"

namespace basic
{
    ListNode *createList (const vector<int> &vals)
    {
        ListNode *head = NULL;
        ListNode *curr = NULL;
        for (auto v : vals)
        {
            if (! head)
            {
                head = new ListNode (v);
                curr = head;
            }
            else
            {
                ListNode *p = new ListNode (v);
                curr->next = p;
                curr = p;
            }
        }
        return head;
    }

    vector<ListNode*> createLists (const vector<vector<int>> &val_lists)
    {
        vector<ListNode*> olst;
        for (const auto &vals : val_lists)
        {
            ListNode *p = createList (vals);
            olst.push_back (p);
        }
        return olst;
    }
    
    void freeList (ListNode *head)
    {
        ListNode *p = head;
        while (p)
        {
            ListNode *q = p;
            p = p->next;
            delete q;
        }
    }

    void dumpList (const string &title, ListNode *head)
    {
        fprintf (stderr, "%s: [", title.c_str());
        ListNode *p = head;
        while (p)
        {
            fprintf (stderr, "%d ", p->val);
            p = p->next;
        }
        fprintf (stderr, "]\n");
    }
}
