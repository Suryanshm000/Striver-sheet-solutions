// problem link: https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

#include<bits/stdc++.h>
using namespace std;


int findPlatform(int arr[], int dep[], int n)
{
    sort(arr, arr + n);
    sort(dep, dep + n);
    int ans = 1, platForm = 1;
    int i = 1, j = 0;

    while (i < n && j < n) {
        if (arr[i] <= dep[j])
        {
            platForm++;
            i++;
        }
        else if (dep[j] < arr[i])
        {
            platForm--;
            j++;
        }

        ans = max(ans, platForm);
    }
    return ans;
}