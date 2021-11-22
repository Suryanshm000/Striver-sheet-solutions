// problem link: https://leetcode.com/problems/combination-sum/

#include<bits/stdc++.h>
using namespace std;


void findCombinations(int ind, int target, vector<int>&arr, vector<int>&ds, vector<vector<int>>&ans)
{
    if (ind == arr.size())
    {
        if (target == 0)    ans.push_back(ds);
        return;
    }
    if (arr[ind] <= target)
    {
        ds.push_back(arr[ind]);
        // picking the same value but not increasing the index
        findCombinations(ind, target - arr[ind], arr, ds, ans);
        ds.pop_back();
    }

    findCombinations(ind + 1, target, arr, ds, ans);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>>ans;
    vector<int>ds;
    findCombinations(0, target, candidates, ds, ans);
    return ans;
}