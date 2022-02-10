// problem link: https://leetcode.com/problems/same-tree/

#include<bits/stdc++.h>
using namespace std;

bool isSameTree(TreeNode* p, TreeNode* q) {
	// we are doing preorder traversal
	if (p == NULL || q == NULL)    return p == q;

	return (p->val == q->val && isSameTree(p->left, q->left)
	        && isSameTree(p->right, q->right));
}