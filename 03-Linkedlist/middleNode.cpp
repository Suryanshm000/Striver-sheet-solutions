// problem link: https://leetcode.com/problems/middle-of-the-linked-list/

#include<bits/stdc++.h>
using namespace std;


ListNode* middleNode(ListNode* head) {
    ListNode* slow = head, *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}