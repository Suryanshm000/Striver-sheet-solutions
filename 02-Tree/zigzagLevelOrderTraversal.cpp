// problem link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
	vector<vector<int>> ans;
	if (root == NULL) return ans;

	queue< TreeNode*> q;
	q.push(root);
	int leftToRight = 1;

	while (!q.empty()) {
		int size = q.size();
		// temporary vector for storing values at particular level
		vector<int>v(size);

		for (int i = 0; i < size; i++) {
			TreeNode* t = q.front();
			q.pop();
			if (leftToRight)
				v[i] = t->val;
			else
				// storing elements in temp vector from last
				v[size - i - 1] = t->val;

			if (t->left)
				q.push(t->left);
			if (t->right)
				q.push(t->right);
		}
		ans.push_back(v);

		if (leftToRight == 1) leftToRight = 0;
		else leftToRight = 1;
	}
	return ans;
}