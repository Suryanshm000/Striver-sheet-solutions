// problem link: https://leetcode.com/problems/house-robber/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    // ind is starting from n-1
    int solve(vector<int>nums, int ind, vector<int> &t) {
        if (ind == 0)
            return nums[ind];
        if (ind < 0)
            return 0;

        if (t[ind] != -1)
            return t[ind];

        // either to add current element and call for n-2
        // or don't add current element call n-1
        int ans = max(nums[ind] + solve(nums, ind - 2, t), solve(nums, ind - 1, t));
        return t[ind] = ans;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> t(n, -1);
        return solve(nums, n - 1, t);
    }
};


// bottom up

int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1)
        return nums[0];
    // storing values of nums into t
    vector<int> t(nums);

    // at index 1 store max value from 1 or 0 index
    t[1] = max(t[1], t[0]);

    for (int i = 2; i < n; i++)
        t[i] = max(nums[i] + t[i - 2], t[i - 1]);

    return t[n - 1];
}