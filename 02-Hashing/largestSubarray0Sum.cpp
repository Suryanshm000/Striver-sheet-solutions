// problem link: https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

#include<bits/stdc++.h>
using namespace std;


int maxLen(int A[], int n)
{
    map <int, int> m;

    int sum = 0, mx = 0;
    for (int i = 0; i < n; i++)
    {
        sum += A[i];
        if (sum == 0)
            mx = i + 1;

        else
        {
            if (m.find(sum) != m.end())
                mx = max(i - m[sum], mx);
            else
                m[sum] = i;
        }
    }
    return mx;
}