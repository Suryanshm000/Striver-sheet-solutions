// problem link: https://leetcode.com/problems/4sum/

#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        if (i != 0 && nums[i] == nums[i - 1]) continue;

        for (int j = i + 1; j < nums.size(); j++)
        {
            if (j != i + 1 && nums[j] == nums[j - 1]) continue;

            int target2 = target - nums[i] - nums[j];
            int front = j + 1;
            int back = nums.size() - 1;
            while (front < back)
            {

                if ((nums[front] + nums[back]) > target2)
                    back--;
                else if ((nums[front] + nums[back]) < target2)
                    front++;
                else
                {
                    vector<int> quad;
                    quad.push_back(nums[i]);
                    quad.push_back(nums[j]);
                    quad.push_back(nums[front]);
                    quad.push_back(nums[back]);
                    ans.push_back(quad);
                    while (front < back && nums[front] == quad[2])
                        front++;
                    while (front < back && nums[back] == quad[3])
                        back--;
                }

            }
        }
    }
    return ans;
}