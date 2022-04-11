// problem link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

#include<bits/stdc++.h>
using namespace std;

bool checkBFS(vector<int> adj[], int s, vector<bool> &vis)
{
	vis[s] = true;
	queue<pair<int, int>> q;
	// storing node and parent value
	q.push({s, -1});

	while (!q.empty())
	{
		int currNode = q.front().first;
		int par = q.front().second;
		q.pop();

		for (auto it : adj[currNode])
		{
			if (!vis[it])
			{
				vis[it] = true;
				q.push({it, currNode});
			}
			else if (par != it)
				return true;
		}
	}
	return false;
}

bool isCycle(int V, vector<int> adj[]) {
	// Code here
	vector<bool> vis(V, false);
	for (int i = 0; i < V; i++)
	{
		if (!vis[i])
		{
			if (checkBFS(adj, i, vis))
				return true;
		}
	}
	return false;
}