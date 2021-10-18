// problem link: https://leetcode.com/problems/sort-colors

#include<bits/stdc++.h>
using namespace std;


void sortColors(vector<int>& nums) {
    int l = 0, m = 0, h = nums.size() - 1;

    while (m <= h)
    {
        if (nums[m] == 0)
            swap(nums[m++], nums[l++]);

        else if (nums[m] == 1)
            m++;

        else
            swap(nums[m], nums[h--]);
    }
}