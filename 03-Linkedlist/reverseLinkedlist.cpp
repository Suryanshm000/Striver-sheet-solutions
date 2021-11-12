// problem link: https://leetcode.com/problems/reverse-linked-list/

#include<bits/stdc++.h>
using namespace std;


ListNode* reverseList(ListNode* head) {
    if (head == NULL)
        return head;
    ListNode* curr, *prev, *next;
    curr = head;
    prev = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}