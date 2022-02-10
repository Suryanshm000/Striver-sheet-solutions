// problem link: https://leetcode.com/problems/single-element-in-a-sorted-array/

#include<bits/stdc++.h>
using namespace std;


int singleNonDuplicate(vector<int>& nums) {
    int low = 0, high = nums.size() - 2;

    while (low <= high) {
        int mid = (low + high) / 2;
        // for left array part (mid^1) give next next odd(for current even) and
        // previous even(for current odd index)

        // Checking for left half
        if (nums[mid] == nums[mid ^ 1])
            low = mid + 1;
        // for right half
        else
            high = mid - 1;
    }
    return nums[low];
}