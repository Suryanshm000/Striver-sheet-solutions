// problem link: https://leetcode.com/problems/reverse-nodes-in-k-group/

#include<bits/stdc++.h>
using namespace std;


ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == NULL || k == 1)    return head;

    ListNode* dummy = new ListNode();
    dummy->next = head;
    ListNode* curr = dummy, *nex = dummy, *pre = dummy;
    int cnt = 0;

    // Counting number of nodes
    while (curr->next != NULL) {
        cnt++;
        curr = curr->next;
    }

    // Traversing the Linked list
    while (cnt >= k) {
        curr = pre->next;
        nex = curr->next;
        for (int i = 1; i < k; i++) {
            curr->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = curr->next;
        }
        pre = curr;
        cnt -= k;
    }
    return dummy->next;
}