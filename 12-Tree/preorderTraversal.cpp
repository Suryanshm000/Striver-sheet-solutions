// problem link: https://leetcode.com/problems/binary-tree-preorder-traversal/

#include<bits/stdc++.h>
using namespace std;

void preorder(TreeNode* root,  vector<int>&ans)
{
	if (root == NULL) return ;
	ans.push_back(root->val);
	preorder(root->left, ans);
	preorder(root->right, ans);
}

vector<int> preorderTraversal(TreeNode* root) {
	vector<int>ans;
	preorder(root, ans);
	return ans;
}

