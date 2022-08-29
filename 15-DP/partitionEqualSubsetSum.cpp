// problem link: https://leetcode.com/problems/partition-equal-subset-sum/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    bool isSubsetSum(int N, vector<int>&arr, int sum)
    {
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
            for (int j = 1; j < sum + 1; j++)
            {
                if (arr[i - 1] <= j)
                    t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
                else
                    t[i][j] = t[i - 1][j];
            }
        return t[N][sum];
    }

    bool canPartition(vector<int>& arr) {
        long sum = 0;
        int N = arr.size();
        for (int i = 0; i < N; i++)
            sum += arr[i];
        if (sum % 2 != 0)
            return 0;
        else
            // now problem is reduced to find subset whose sum is sum/2
            return isSubsetSum(N, arr, sum / 2);
    }
};