// problem link: https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1

#include<bits/stdc++.h>
using namespace std;

vector<int> topView(Node *root)
{
	vector<int>ans;
	if (root == NULL) return ans;

	map<int, int> m;			// ordered Map is used to store nodes at a particular horizontal distance
	queue<pair< Node*, int>> q;		// queue store node with its distance
	q.push({root, 0});

	while (! q.empty())
	{
		Node* temp = q.front().first ;
		int d = q.front().second ;
		q.pop();

		if (m.find(d) == m.end())		// if distance doesn't exist in map then push
			m[d] = temp->data;

		if (temp->left)
			q.push({temp->left, d - 1});
		if (temp->right)
			q.push({temp->right, d + 1});
	}
	for (auto it = m.begin(); it != m.end(); it++)		// map is odered
		ans.push_back(it-> second);
	return ans;
}