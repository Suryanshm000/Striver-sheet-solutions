// problem link: https://leetcode.com/problems/linked-list-cycle/

#include<bits/stdc++.h>
using namespace std;


bool hasCycle(ListNode *head) {
    ListNode* slow = head, *fast = head;
    if (head == NULL || head->next == NULL)
        return false;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }

    return false;
}