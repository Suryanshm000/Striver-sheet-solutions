// problem link: https://leetcode.com/problems/balanced-binary-tree/

#include<bits/stdc++.h>
using namespace std;

int height(TreeNode* root) {
	if (root == NULL)    return 0;

	int lh = height(root->left);
	if (lh == -1)    return -1;
	int rh = height(root->right);
	if (rh == -1)    return -1;

	// if heights differ then we return -1 for unbalanced tree
	if (abs(lh - rh) > 1)  return -1;
	return max(lh, rh) + 1;
}

bool isBalanced(TreeNode* root) {
	int h = height(root);
	if (h == -1) return false;
	return true;
}