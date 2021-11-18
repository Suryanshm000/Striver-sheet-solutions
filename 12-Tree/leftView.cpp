// problem link: https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1

#include<bits/stdc++.h>
using namespace std;

vector<int> leftSideView(TreeNode* root) {
	vector<int> ans;
	if (root == NULL)    return ans;
	queue< TreeNode* > q;
	q.push(root);

	while (!q.empty())
	{
		TreeNode* temp;
		int size = q.size();
		while (size--) {
			temp = q.front();
			q.pop();
			// first push right side for showing left side
			if (temp->right)
				q.push(temp->right);
			if (temp->left)
				q.push(temp->left);
		}
		ans.push_back(temp->val);
	}
	return ans;
}