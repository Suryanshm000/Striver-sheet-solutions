// problem link: https://leetcode.com/problems/palindrome-partitioning/

#include<bits/stdc++.h>
using namespace std;


bool palindrome(string s, int start, int end) {
    while (start <= end)
    {
        if (s[start++] != s[end--])
            return false;
    }
    return true;
}

void parti(int ind, string s, vector<string> &path, vector<vector<string>> &ans) {
    if (ind == s.size())
    {
        ans.push_back(path);
        return ;
    }
    for (int i = ind; i < s.size(); i++)
    {
        if (palindrome(s, ind, i))
        {
            path.push_back(s.substr(ind, i - ind + 1));
            parti(i + 1, s, path, ans);
            path.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> path;
    parti(0, s, path, ans);

    return ans;
}