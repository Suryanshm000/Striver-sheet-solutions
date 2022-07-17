// problem link: https://leetcode.com/problems/minimum-path-sum/

#include<bits/stdc++.h>
using namespace std;


// dp with memoization
class Solution {
public:
    int pathSum(int i, int j, int m, int n, vector<vector<int>>& grid, vector<vector<int>>&dp)
    {
        // if we reach out of grid then just don't take it
        if (i == m || j == n)
            return 999999;

        if (i == m - 1 && j == n - 1)
            return grid[i][j];

        if (dp[i][j] != -1)
            return dp[i][j];

        // take min from up and left by adding current val
        dp[i][j] = min(grid[i][j] + pathSum(i + 1, j, m, n, grid, dp),
                       grid[i][j] + pathSum(i, j + 1, m, n, grid, dp));

        return dp[i][j];
    }


    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return pathSum(0, 0, m, n, grid, dp);
    }
};



// bottom up

class Solution {
public:

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // adding value in given matrix
        // add prev. row to next at 0th col
        for (int i = 1; i < m; i++)
            grid[i][0] += grid[i - 1][0];

        // add prev. col to next at 0th row
        for (int j = 1; j < n; j++)
            grid[0][j] += grid[0][j - 1];

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                // min accepted either left or up
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid[m - 1][n - 1];
    }
};