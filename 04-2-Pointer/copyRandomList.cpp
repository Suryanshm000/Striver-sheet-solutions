// problem link: https://leetcode.com/problems/copy-list-with-random-pointer/

#include<bits/stdc++.h>
using namespace std;


Node* copyRandomList(Node* head) {
    Node *it = head;
    Node *front = head;

    // First round - make copy of each node,
    // and link them together side-by-side in a single list.
    while (it != NULL) {
        front = it->next;

        Node *copy = new Node(it->val);
        it->next = copy;
        copy->next = front;

        it = front;
    }

    // Second round - assign random pointers for the copy nodes.
    it = head;
    while (it != NULL) {
        if (it->random != NULL) {
            it->next->random = it->random->next;
        }
        it = it->next->next;
    }

    // Third round - restore the original list, and extract the copy list.
    it = head;
    Node *pseudoHead = new Node(0);
    Node *copy = pseudoHead;

    while (it != NULL) {
        front = it->next->next;

        // extract the copy
        copy->next = it->next;

        // restore the original list
        it->next = front;

        copy = copy -> next;
        it = front;
    }

    return pseudoHead->next;
}
