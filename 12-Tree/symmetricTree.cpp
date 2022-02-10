// problem link: https://leetcode.com/problems/symmetric-tree/

#include<bits/stdc++.h>
using namespace std;

bool isMirror(TreeNode* l, TreeNode* r)
{
	if (l == NULL || r == NULL)
		return l == r;
	if (l->val != r->val)    return false;

	// checking left of one tree with right of other tree
	return isMirror(l->left, r->right) && isMirror(l->right, r->left);
}

bool isSymmetric(TreeNode* root) {
	return isMirror(root->left, root->right);
}