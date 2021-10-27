// problem link: https://leetcode.com/problems/binary-tree-inorder-traversal/

#include<bits/stdc++.h>
using namespace std;

void inorder(TreeNode* root,  vector<int>&ans)
{
	if (root == NULL) return ;

	inorder(root->left, ans);
	ans.push_back(root->val);
	inorder(root->right, ans);
}

vector<int> inorderTraversal(TreeNode* root) {
	vector<int> ans;
	inorder(root, ans);
	return ans;
}

