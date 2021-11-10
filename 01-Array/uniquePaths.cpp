// problem link: https://leetcode.com/problems/unique-paths/

#include<bits/stdc++.h>
using namespace std;


// best soln using combination N C r

int uniquePaths(int m, int n) {
    int N = m + n - 2;
    int r = m - 1;
    double ans = 1;
    for (int i = 1; i <= r; i++)
    {
        ans = ans * (N - r + i) / i;
    }
    return int(ans);
}


// DP solution

// int diffPaths(int i, int j, int m, int n, vector<vector<int>>&v)
// {
//     if (i == m || j == n)    return 0;
//     if (i == m - 1 && j == n - 1) return 1;

//     if (v[i][j] != -1)   return v[i][j];        // if their paths already present

//     return v[i][j] = diffPaths(i + 1, j, m, n, v) + diffPaths(i, j + 1, m, n, v);
// }

// int uniquePaths(int m, int n) {
//     vector<vector<int>> v(m, vector<int> (n, -1));  // matrix for storing their paths
//     int ans = diffPaths(0, 0, m, n, v);
//     return ans;
// }