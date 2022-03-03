// problem link: https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

#include<bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
	vector<int>ans;
	queue<int> q;
	vector<bool> visited(V, false);

	// graph is starting from node of value 0
	q.push(0);
	visited[0] = true;

	ans.push_back(0);

	while (!q.empty())
	{
		int currNode = q.front();
		q.pop();
		// traversing a level completely then move to next level
		for (auto ele : adj[currNode])
		{
			// push only non visited node into queue
			if (visited[ele] == false)
			{
				q.push(ele);
				visited[ele] = true;
				ans.push_back(ele);
			}
		}
	}
	return ans;
}