// problem link: https://leetcode.com/problems/add-two-numbers/

#include<bits/stdc++.h>
using namespace std;


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    // list is given in reverse form
    // creating dummy node
    ListNode *temp = new ListNode();
    ListNode* curr = temp;
    int c = 0;
    while (l1 != NULL || l2 != NULL || c)
    {
        int sm = 0;
        if (l1 != NULL)
        {
            sm += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL)
        {
            sm += l2->val;
            l2 = l2->next;
        }
        sm += c;
        c = sm / 10;
        ListNode *in = new ListNode(sm % 10);
        curr->next = in;
        curr = curr->next;
    }
    return temp->next;
}