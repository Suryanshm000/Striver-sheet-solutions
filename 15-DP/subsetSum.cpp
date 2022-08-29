// problem link: https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

#include<bits/stdc++.h>
using namespace std;


bool isSubsetSum(int N, int arr[], int sum) {
    bool t[N + 1][sum + 1];

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= sum; j++) {
            if (i == 0)
                t[i][j] = false;
            if (j == 0)
                t[i][j] = true;
        }
    }

    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            // is value is less than equal to required sum
            if (arr[i - 1] <= j)
                t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
            else
                t[i][j] = t[i - 1][j];
        }
    }
}