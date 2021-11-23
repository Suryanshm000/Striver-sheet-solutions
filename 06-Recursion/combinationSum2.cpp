// problem link: https://leetcode.com/problems/combination-sum-ii/

#include<bits/stdc++.h>
using namespace std;


void findCombination(int ind, int target, vector<int>&arr, vector<int>&v, vector<vector<int>>&ans)
{
    if (target == 0) {
        ans.push_back(v);
        return;
    }

    for (int i = ind; i < arr.size(); i++)
    {
        if (i != ind && arr[i] == arr[i - 1])    continue;
        if (arr[i] > target)    break;

        v.push_back(arr[i]);
        findCombination(i + 1, target - arr[i], arr, v, ans);
        v.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<int>v;
    vector<vector<int>> ans;
    sort(candidates.begin(), candidates.end());
    findCombination(0, target, candidates, v, ans);

    return ans;
}