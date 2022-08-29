// problem link: https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

#include<bits/stdc++.h>
using namespace std;


// 0-1 knapSack problem   --- top down

int dpknapSack(int W, int wt[], int val[], int n, vector<vector<int>> &t) {
    if (n == 0 || W == 0)
        return 0;
    // if the value is already present in table
    if (t[n][W] != -1)
        return t[n][W];

    else if (wt[n - 1] <= W)
        return t[n][W] = max(val[n - 1] + dpknapSack(W - wt[n - 1], wt, val, n - 1, t),
                             dpknapSack(W, wt, val, n - 1, t));
    else if (wt[n - 1] > W)
        return t[n][W] = dpknapSack(W, wt, val, n - 1, t);
}

int knapSack(int W, int wt[], int val[], int n)
{
    vector<vector<int>> t(n + 1, vector<int>(W + 1, -1));
    return dpknapSack(W, wt, val, n, t);
}



// bottom up approach

int knapSack(int W, int wt[], int val[], int n)
{
    int t[n + 1][W + 1];

    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < W + 1; j++) {
            if (i == 0 || j == 0)
                t[i][j] = 0;
            else if (wt[i - 1] <= j)
                t[i][j] = max(val[i - 1] + t[i - 1][j - wt[i - 1]], t[i - 1][j]);
            else
                t[i][j] = t[i - 1][j];
        }
    return t[n][W];
}