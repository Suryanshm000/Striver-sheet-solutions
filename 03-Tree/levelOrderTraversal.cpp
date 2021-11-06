// problem link: https://leetcode.com/problems/binary-tree-level-order-traversal/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> levelOrder(TreeNode* root) {
	vector<vector<int>> ans;

	if (root == NULL) return ans;

	queue< TreeNode*> q;
	q.push(root);

	while (!q.empty()) {
		int size = q.size();
		// temporary vector for storing values at particular level
		vector<int>v;

		while (size--) {
			TreeNode* t = q.front();
			q.pop();
			v.push_back(t->val);
			if (t->left)
				q.push(t->left);
			if (t->right)
				q.push(t->right);
		}
		ans.push_back(v);
	}
	return ans;
}
