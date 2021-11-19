// problem link: https://leetcode.com/problems/3sum/

#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 2; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1]) continue;      // it is duplicate

        int l = i + 1, r = n - 1;
        int reqsum = 0 - nums[i];               // a+b+c = 0 means a+b = -c
        while (l < r)
        {
            if (reqsum < nums[l] + nums[r])
                r--;
            else if (reqsum > nums[l] + nums[r])
                l++;
            else {
                vector<int>t(3);
                t[0] = nums[i];
                t[1] = nums[l];
                t[2] = nums[r];
                ans.push_back(t);
                while (l < r && nums[l] == t[1])        // leaving duplicates
                    l++;
                while (l < r && nums[r] == t[2])
                    r--;
            }
        }
    }
    return ans;
}