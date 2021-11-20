// problem link: https://leetcode.com/problems/max-consecutive-ones/

#include<bits/stdc++.h>
using namespace std;


int findMaxConsecutiveOnes(vector<int>& nums) {
    int max1 = 0;
    int currmax = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1)
            currmax++;
        else
            currmax = 0;
        max1 = max(currmax, max1);
    }
    return max1;
}