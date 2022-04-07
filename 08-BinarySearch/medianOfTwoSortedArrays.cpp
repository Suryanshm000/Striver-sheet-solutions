// problem link: https://leetcode.com/problems/median-of-two-sorted-arrays/

#include<bits/stdc++.h>
using namespace std;


double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    // choosing nums1 as small
    if (nums2.size() < nums1.size())
        return findMedianSortedArrays(nums2, nums1);

    int n1 = nums1.size();
    int n2 = nums2.size();
    int low = 0, high = n1;

    // finding the element which is median by partitioning from both arrays
    while (low <= high)
    {
        // cut1 means no. of elements from array 1
        int cut1 = (low + high) / 2;
        // no. of elements from array 2
        int cut2 = (n1 + n2 + 1) / 2 - cut1;

        // largest of array 1 is left1
        int left1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
        int left2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];

        // if all elements on left side then set right to max
        int right1 = cut1 == n1 ? INT_MAX : nums1[cut1];
        int right2 = cut2 == n2 ? INT_MAX : nums2[cut2];


        if (left1 <= right2 && left2 <= right1)
        {
            // n1 + n2 is even
            if ( (n1 + n2) % 2 == 0 )
                return (max(left1, left2) + min(right1, right2)) / 2.0;
            else
                return max(left1, left2);
        }

        // invalid partition from 1st array then move backward
        else if (left1 > right2)
            high = cut1 - 1;
        // move forward in array1
        else
            low = cut1 + 1;
    }
    return 0.0;
}