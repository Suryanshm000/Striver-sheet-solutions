// problem link: https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1

#include<bits/stdc++.h>
using namespace std;


Node* merge(Node *a, Node* b) {
    Node* temp = new Node(0);
    Node* ans = temp;

    while (a && b)
    {
        // checking values from top to bottom
        if (a->data < b->data)
        {
            temp->bottom = a;
            temp = temp->bottom;
            a = a->bottom;
        }
        else
        {
            temp->bottom = b;
            temp = temp->bottom;
            b = b->bottom;
        }
    }

    if (a)
        temp->bottom = a;
    else
        temp->bottom = b;

    ans->bottom->next = NULL;

    return ans->bottom;
}

Node *flatten(Node *root)
{
    if (root == NULL || root->next == NULL)   return root;

    // reaching to last list
    root->next = flatten(root->next);
    // then merge 2 list from last
    root = merge(root, root->next);

    return root;
}
