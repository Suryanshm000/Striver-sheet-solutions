// problem link: https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

#include<bits/stdc++.h>
using namespace std;

vector <int> bottomView(Node *root) {
	vector<int>ans;
	if (root == NULL) return ans;

	map<int, int> m;			// Map to store nodes at a particular horizontal distance
	queue<pair< Node*, int>> q;
	q.push({root, 0});
	while (! q.empty())
	{
		Node* temp = q.front().first ;
		int d = q.front().second ;
		q.pop();

		m[d] = temp->data;		 // update the value in map so that we can reach to bottom

		if (temp->left)
			q.push({temp->left, d - 1});
		if (temp->right)
			q.push({temp->right, d + 1});
	}
	for (auto it = m.begin(); it != m.end(); it++)
		ans.push_back(it -> second);
	return ans;
}