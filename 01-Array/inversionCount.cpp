// problem link: https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

#include<bits/stdc++.h>
using namespace std;


long long merge(long long *arr, long long l, long long m, long long r)
{
    long long i, j, k;
    long long n1 = m - l + 1;
    long long n2 = r - m;
    long long L[n1], R[n2];
    long long invcount = 0;

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];

        else
        {
            arr[k++] = R[j++];
            invcount += n1 - i;
        }
    }
    while (i < n1 || j < n2)
    {
        if (i < n1)
            arr[k++] = L[i++];

        else
            arr[k++] = R[j++];
    }

    return invcount;
}

long long mergeSort(long long *arr, long long l, long long r)
{
    long long invcount = 0;
    if (l < r)
    {
        long long m = l + (r - l) / 2;
        invcount += mergeSort(arr, l, m);
        invcount += mergeSort(arr, m + 1, r);
        invcount += merge(arr, l, m, r);
    }
    return invcount;
}

long long int inversionCount(long long arr[], long long N)
{

    long long ans = mergeSort(arr, 0, N - 1);

    return ans;
}