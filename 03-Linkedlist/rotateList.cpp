// problem link: https://leetcode.com/problems/rotate-list/description/

#include<bits/stdc++.h>
using namespace std;


ListNode* rotateRight(ListNode* head, int k) {
    if (!head || !head->next || k == 0)    return head;

    int len = 1;
    ListNode* temp = head;
    while (temp->next)
    {
        // finding the length of ll
        len++;
        temp = temp->next;
    }

    // creating circular list
    temp->next = head;
    k = k % len;
    k = len - k;

    while (k--)
        temp = temp->next;

    // new head of rotated list
    head = temp->next;
    temp->next = NULL;

    return head;
}
