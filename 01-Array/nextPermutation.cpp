// problem link: https://leetcode.com/problems/next-permutation/

#include<bits/stdc++.h>
using namespace std;


void nextPermutation(vector<int>& nums) {
    int f, s;
    for (f  = nums.size() - 2; f >= 0; f--)
        // finding first element from last which is creating increasing order
        if (nums[f] < nums[f + 1])
            break;

    // if given array is sorted in descending order
    if (f < 0)
        reverse(nums.begin(), nums.end());
    else
    {
        for (s = nums.size() - 1; s > f; s--)
        {
            // finding second element after first so that we can swap them
            if (nums[s] > nums[f])
                break;
        }
        swap(nums[f], nums[s]);
        reverse(nums.begin() + f + 1, nums.end());
    }
}