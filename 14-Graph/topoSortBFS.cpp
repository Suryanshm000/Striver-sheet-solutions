// problem link: https://practice.geeksforgeeks.org/problems/topological-sort/1

#include<bits/stdc++.h>
using namespace std;

// Khan's algo

vector<int> topoSort(int V, vector<int> adj[])
{
	vector<int>topo;
	vector<int> inDeg(V, 0);
	queue<int>q;

	for (int i = 0; i < V; i++)
		// reach to every adjacent of vertex and increase indegree to that adjacent
		for (auto x : adj[i])
			inDeg[x]++;

	for (int i = 0; i < V; i++)
		if (inDeg[i] == 0)
			q.push(i);

	while (!q.empty())
	{
		int t = q.front();
		q.pop();
		// push this in result
		topo.push_back(t);
		for (auto x : adj[t])
		{
			// cause its parent node is removed so remove one degree
			inDeg[x]--;
			if (inDeg[x] == 0)
				q.push(x);
		}
	}
	return topo;
}