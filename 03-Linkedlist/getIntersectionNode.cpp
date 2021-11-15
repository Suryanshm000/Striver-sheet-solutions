// problem link: https://leetcode.com/problems/intersection-of-two-linked-lists/

#include<bits/stdc++.h>
using namespace std;


ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headA == NULL || headB == NULL)
        return NULL;
    ListNode* a = headA, *b = headB;
    while (a != b)
    {
        // if any dummy node is null then assign head of other list
        a = a == NULL ? headB : a->next;
        b = b == NULL ? headA : b->next;
    }
    return a;
}