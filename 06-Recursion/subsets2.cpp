// problem link: https://practice.geeksforgeeks.org/problems/subset-sums2234/1

#include<bits/stdc++.h>
using namespace std;


void findSubsets(int ind, vector<int> &n, vector<vector<int>> &ans, vector<int> &v)
{
    ans.push_back(v);
    for (int i = ind; i < n.size(); i++)
    {
        if (i != ind && n[i] == n[i - 1])    continue;

        v.push_back(n[i]);
        findSubsets(i + 1, n, ans, v);
        v.pop_back();           // need to remove element after all its subsets
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int>v;
    // sort for removing duplicates
    sort(nums.begin(), nums.end());

    findSubsets(0, nums, ans, v);
    return ans;
}