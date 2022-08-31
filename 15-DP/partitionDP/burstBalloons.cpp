// problem link: https://leetcode.com/problems/burst-balloons/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int part(int i, int j, vector<int>& a, vector<vector<int>>&dp)
    {
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        int mx = INT_MIN;
        for (int ind = i; ind <= j; ind++)
        {
            // bursting ind as last element present
            int coins = a[i - 1] * a[ind] * a[j + 1] + part(i, ind - 1, a, dp) +
                        part(ind + 1, j, a, dp);
            mx = max(mx, coins);
        }
        return dp[i][j] = mx;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        // at extreme left and right coins can get is only 1
        nums.push_back(1);
        nums.insert(nums.begin(), 1);

        vector<vector<int>>t(n + 1, vector<int>(n + 1, -1));

        return part(1, n, nums, t);
    }
};