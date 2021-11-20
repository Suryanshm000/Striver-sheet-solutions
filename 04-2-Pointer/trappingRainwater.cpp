// problem link: https://leetcode.com/problems/trapping-rain-water/

#include<bits/stdc++.h>
using namespace std;


int trap(vector<int>& height) {
    int n = height.size();
    int l = 0, r = n - 1, ans = 0;
    int maxleft = 0, maxright = 0;

    while (l <= r)
    {
        if (height[l] <= height[r])
        {
            if (maxleft <= height[l]) maxleft = height[l];
            else ans += maxleft - height[l];

            l++;
        }
        else
        {
            if (maxright <= height[r]) maxright = height[r];
            else ans += maxright - height[r];

            r--;
        }
    }
    return ans;
}
