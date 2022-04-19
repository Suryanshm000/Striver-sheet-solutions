// problem link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1/

#include<bits/stdc++.h>
using namespace std;

// detect cycle in a directed graph.   =======   DFS   =======
bool checkCycle(int node, vector < int > adj[], int vis[], int dfsVis[])
{
	vis[node] = 1;
	dfsVis[node] = 1;
	for (auto it : adj[node])
	{
		if (!vis[it])
		{
			if (checkCycle(it, adj, vis, dfsVis)) return true;
		}
		// if it is visited at dfs path from which we are coming
		else if (dfsVis[it])
			return true;
	}
	dfsVis[node] = 0;
	return false;
}

bool isCyclic(int N, vector < int > adj[])
{
	int vis[N], dfsVis[N];
	memset(vis, 0, sizeof vis);
	memset(dfsVis, 0, sizeof dfsVis);

	for (int i = 0; i < N; i++)
	{
		if (!vis[i])
		{
			if (checkCycle(i, adj, vis, dfsVis))
				return true;
		}
	}
	return false;
}
