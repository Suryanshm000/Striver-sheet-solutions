// problem link: https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1

#include<bits/stdc++.h>
using namespace std;


int kthElement(int arr1[], int arr2[], int n, int m, int k)
{
    if (n > m)
        return kthElement(arr2, arr1, m, n, k);

    int low = max(0, k - m), high = min(k, n);

    while (low <= high)
    {
        // cut1 means no. of elements from array 1
        int cut1 = (low + high) >> 1;
        // no. of elements from array 2
        int cut2 = k - cut1;

        // largest of array 1
        int left1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1];

        int left2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];

        int right1 = cut1 == n ? INT_MAX : arr1[cut1];
        int right2 = cut2 == m ? INT_MAX : arr2[cut2];


        if (left1 <= right2 && left2 <= right1)
            return max(left1, left2);

        // invalid partition from 1st array then move backward
        else if (left1 > right2)
            high = cut1 - 1;
        // move forward in array1
        else
            low = cut1 + 1;
    }
    return 1;
}