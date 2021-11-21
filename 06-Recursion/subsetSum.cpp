// problem link: https://practice.geeksforgeeks.org/problems/subset-sums2234/1

#include<bits/stdc++.h>
using namespace std;


void subSum(int ind, int sum, vector<int> &a, int N, vector<int>&sub)
{
    if (ind == N)
    {
        sub.push_back(sum);
        return ;
    }
    // to select the sum
    subSum(ind + 1, sum + a[ind], a, N, sub);
    // do not select the sum
    subSum(ind + 1, sum, a, N, sub);
}

vector<int> subsetSums(vector<int> arr, int N)
{
    vector<int>sub;
    subSum(0, 0, arr, N, sub);
    sort(sub.begin(), sub.end());       //  answer should be in sorted order

    return sub;
}