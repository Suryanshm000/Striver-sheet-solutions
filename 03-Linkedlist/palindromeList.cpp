// problem link: https://leetcode.com/problems/palindrome-linked-list/

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

bool isPalindrome(ListNode* head) {
    ListNode* s = head, *f = head;
    // finding middle of list   1, 2->Middle, 2, 1
    while (f->next && f->next->next)
    {
        f = f->next->next;
        s = s->next;
    }

    // reversing right List     1,2,1,2
    s->next = reverseList(s->next);
    s = s->next;
    while (s)
    {
        if (s->val != head->val)
            return false;
        s = s->next;
        head = head->next;
    }
    return true;
}