// problem link: https://leetcode.com/problems/search-in-rotated-sorted-array/

#include<bits/stdc++.h>
using namespace std;


int search(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if (nums[mid] == target)
            return mid;

        // left half is sorted
        if (nums[low] <= nums[mid])
        {
            if (nums[low] <= target && nums[mid] >= target)
                high = mid - 1;

            // discard the left half
            else
                low = mid + 1;
        }
        // right half is sorted
        else
        {
            if (nums[mid] <= target && target <= nums[high])
                low = mid + 1;
            // discard the right half
            else
                high = mid - 1;
        }
    }
    return -1;
}
