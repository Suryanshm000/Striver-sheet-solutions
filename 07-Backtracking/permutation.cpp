// problem link: https://leetcode.com/problems/permutations/

#include<bits/stdc++.h>
using namespace std;


void recPermute(int ind, vector<int>&nums, vector<vector<int>> &ans)
{
    if (ind == nums.size())
    {
        ans.push_back(nums);
        return;
    }

    for (int i = ind; i < nums.size(); i++) {
        swap(nums[i], nums[ind]);
        recPermute(ind + 1, nums, ans);
        swap(nums[i], nums[ind]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    recPermute(0, nums, ans);
    return ans;
}