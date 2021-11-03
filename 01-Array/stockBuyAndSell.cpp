// problem link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include<bits/stdc++.h>
using namespace std;


int maxProfit(vector<int>& prices) {
    int mn = INT_MAX, ans = 0;
    for (int i = 0; i < prices.size(); i++)
    {
        // continuosly finding min value
        mn = min(mn, prices[i]);
        // max profit
        ans = max(ans, prices[i] - mn);
    }
    return ans;
}