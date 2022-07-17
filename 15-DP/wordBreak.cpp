// problem link: https://leetcode.com/problems/word-break/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    bool rec(int ind, string s, set<string> st, vector<int> &dp)
    {
        if (ind == s.size())
            return true;

        if (dp[ind] != -1)
            return dp[ind];

        // start from ind to check if this string present in set
        for (int i = ind; i < s.size(); i++)
        {
            if (st.count(s.substr(ind, i - ind + 1)) && rec(i + 1, s, st, dp))
                return dp[ind] = true;
        }
        return dp[ind] = false;
    }


    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        // strore words in set
        for (auto x : wordDict)
            st.insert(x);

        vector<int> dp(s.size(), -1);

        return rec(0, s, st, dp);
    }
};