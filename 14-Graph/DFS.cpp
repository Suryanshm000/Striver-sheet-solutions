// problem link: https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

#include<bits/stdc++.h>
using namespace std;

void dfs(int node, int visited[], vector<int> adj[], vector<int> &ans)
{
	if (visited[node] != 0)
		return ;
	// mark the current node as visited
	visited[node] = 1;
	ans.push_back(node);

	// finding adjacent of given node then move to depth
	for (auto x : adj[node]) {
		if (visited[x] != 1)
			dfs(x, visited, adj, ans);
	}
}

vector<int> dfsOfGraph(int v, vector<int> adj[]) {
	int visited[v];
	// initialising to 0
	memset(visited, 0, sizeof visited);

	vector<int> ans;
	dfs(0, visited, adj, ans);
	return ans;
}