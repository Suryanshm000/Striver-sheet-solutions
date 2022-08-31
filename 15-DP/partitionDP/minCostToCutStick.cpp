// problem link: https://leetcode.com/problems/minimum-cost-to-cut-a-stick/

#include<bits/stdc++.h>
using namespace std;


int partition(int i, int j, vector<int>& cuts, vector<vector<int>>&dp)
{
    if (i > j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    int mn = 1e9;

    // partition it into differnt cuts given
    for (int k = i; k <= j; k++)
    {
        // cut at a point and solve left and right
        int cost = ( cuts[j + 1] - cuts[i - 1] +
                     partition(i, k - 1, cuts, dp) +
                     partition(k + 1, j, cuts, dp));
        mn = min(mn, cost);
    }

    return dp[i][j] = mn;
}

int minCost(int n, vector<int>& cuts) {
    int c = cuts.size();
    // n is length to insert at last and 0 at begin
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);

    // sorting is required to solve cut parts independently
    sort(cuts.begin(), cuts.end());


    vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));
    return partition(1, c, cuts, dp);
}