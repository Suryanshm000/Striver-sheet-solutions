// problem link: https://leetcode.com/problems/binary-tree-maximum-path-sum/

#include<bits/stdc++.h>
using namespace std;

int findSum(TreeNode* root, int &maxi)
{
	if (!root)   return 0;

	int left = max(0, findSum(root->left, maxi));		// neglecting negative val
	int right = max(0, findSum(root->right, maxi));

	maxi = max(maxi, left + right + root->val);			// storing max path sum

	return root->val + max(left, right);
}

int maxPathSum(TreeNode* root) {
	int maxi = INT_MIN;
	findSum(root, maxi);
	return maxi;
} bool isSameTree(TreeNode* p, TreeNode* q) {
	// we are doing preorder traversal
	if (p == NULL || q == NULL)    return p == q;

	return (p->val == q->val && isSameTree(p->left, q->left)
	        && isSameTree(p->right, q->right));
}