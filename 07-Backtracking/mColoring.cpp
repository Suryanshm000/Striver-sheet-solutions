// problem link: https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1#

#include<bits/stdc++.h>
using namespace std;


bool isSafe(int node, int color[], bool graph[101][101], int n, int col) {
    for (int k = 0; k < n; k++) {
        // if adjacent nodes having same color then false
        if (k != node && graph[k][node] == 1 && color[k] == col) {
            return false;
        }
    }
    return true;
}

bool solve(int node, int color[], int m, int N, bool graph[101][101]) {
    // all the nodes are colored safely
    if (node == N) {
        return true;
    }

    for (int i = 1; i <= m; i++) {
        // check adjacents nodes are of same color or not
        if (isSafe(node, color, graph, N, i)) {
            color[node] = i;
            // move to next node
            if (solve(node + 1, color, m, N, graph))
                return true;
            // if this color  not possible then backtrack
            color[node] = 0;
        }

    }
    return false;
}

//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool graphColoring(bool graph[101][101], int m, int N)
{
    int color[N] = {0};
    if (solve(0, color, m, N, graph)) return true;
    return false;
}