// problem link: https://leetcode.com/problems/merge-two-sorted-lists/

#include<bits/stdc++.h>
using namespace std;


ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* temp = new ListNode();
    temp->next = NULL;
    ListNode *ans = temp ;
    if (l1 == NULL && l2 == NULL)
        return l1;
    else if (l1 == NULL)
        return l2;
    else if (l2 == NULL)
        return l1;
    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            temp->val = l1->val ;
            l1 = l1->next ;
        }
        else if (l1->val > l2->val)
        {
            temp->val = l2->val ;
            l2 = l2->next ;
        }
        else
        {
            temp->val = l1->val ;
            l1 = l1->next ;
        }

        if (l1 && l2)
        {
            temp->next = new ListNode();
            temp = temp->next ;
            temp->next = NULL ;
        }
    }

    while (l1 || l2)
    {
        temp->next = new ListNode();
        temp = temp->next ;
        temp->next = NULL ;
        if (l1)
        {
            temp->val = l1->val ;
            l1 = l1->next ;
        }
        else if (l2)
        {
            temp->val = l2->val ;
            l2 = l2->next ;
        }
    }
    return ans;
}