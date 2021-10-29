// problem link: https://leetcode.com/problems/binary-tree-postorder-traversal/

#include<bits/stdc++.h>
using namespace std;

void postorder(TreeNode* root,  vector<int>&ans)
{
	if (root == NULL) return ;

	postorder(root->left, ans);
	postorder(root->right, ans);
	ans.push_back(root->val);
}

vector<int> postorderTraversal(TreeNode* root) {
	vector<int> ans;
	postorder(root, ans);
	return ans;
}
