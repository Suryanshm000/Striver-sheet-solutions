// problem link: https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int t[101][101];

    int solve(int a[], int i, int j)
    {
        // if there is single matrix
        if (i >= j)
            return 0;
        if (t[i][j] != -1)
            return t[i][j];

        int mn = INT_MAX;
        for (int k = i; k <= j - 1; k++)
        {
            // cost of matrix from i to j + matrix from i to k +  matrix from k+1 to j
            int temp = solve(a, i, k) + solve(a, k + 1, j) + a[i - 1] * a[k] * a[j];
            mn = min(mn, temp);
        }

        return t[i][j] = mn;
    }

    int matrixMultiplication(int N, int arr[])
    {
        memset(t, -1, sizeof(t));
        int ans = solve(arr, 1, N - 1);
        return ans;
    }
};