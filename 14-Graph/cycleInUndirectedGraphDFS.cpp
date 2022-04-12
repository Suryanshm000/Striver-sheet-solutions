// problem link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

#include<bits/stdc++.h>
using namespace std;

bool checkForCycle(int node, int parent, vector < int > & vis, vector < int > adj[]) {
	vis[node] = 1;
	for (auto x : adj[node])
	{
		if (!vis[x])
		{
			if (checkForCycle(x, node, vis, adj))
				return true;
		}
		else if (x != parent)
			return true;
	}

	return false;
}

bool isCycle(int V, vector < int > adj[]) {
	vector < int > vis(V, 0);
	for (int i = 0; i < V; i++) {
		if (!vis[i]) {
			if (checkForCycle(i, -1, vis, adj))
				return true;
		}
	}
	return false;
}