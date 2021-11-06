// problem link: https://leetcode.com/problems/two-sum/

#include<bits/stdc++.h>
using namespace std;


vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> m;
    vector<int> ans;

    for (int i = 0; i < nums.size(); i++)
    {

        if (m.find(target - nums[i]) != m.end())
        {
            // push the indices of two element
            ans.push_back(i);
            ans.push_back(m[target - nums[i]]);
            break;
        }
        m[nums[i]] = i;
    }
    return ans;
}