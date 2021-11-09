// problem link: https://leetcode.com/problems/majority-element/

#include<bits/stdc++.h>
using namespace std;


int majorityElement(vector<int>& nums) {
    int count = 0, ele;
    for (int i = 0; i < nums.size(); i++)
    {
        if (count == 0)
            ele = nums[i];

        if (ele == nums[i]) count++;
        else count--;
    }
    return ele;
}