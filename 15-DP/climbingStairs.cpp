// problem link: https://leetcode.com/problems/climbing-stairs/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int solve(int n, vector<int> &t)
    {
        if (n == 0)
            return 1;
        if (n < 0)
            return 0;

        if (t[n] != -1)
            return t[n];
        // I have come from either 1 step back or 2 step back
        int ans = solve(n - 1, t) + solve(n - 2, t);

        return t[n] = ans;
    }

    int climbStairs(int n) {
        vector<int>t(n + 1, -1);
        solve(n, t);

        return t[n];
    }
};


// bottom up

int climbStairs(int n) {
    vector<int>t(n + 1, 0);
    t[0] = 1;
    t[1] = 1;
    // either come from 1 step or 2 step
    for (int i = 2; i <= n; i++)
        t[i] = t[i - 1] + t[i - 2];

    return t[n];
}