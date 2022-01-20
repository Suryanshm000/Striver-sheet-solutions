// problem link: https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    //Function to get the maximum total value in the knapsack.

    static bool cmp(struct Item a, struct Item b)
    {
        double r1 = (double)a.value / (double)a.weight;
        double r2 = (double)b.value / (double)b.weight;
        return r1 > r2;
    }

    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // sorting according to value/weight
        sort(arr, arr + n, cmp);
        double ans = 0.0;
        int currWeight = 0;

        for (int i = 0; i < n; i++) {
            if (currWeight + arr[i].weight <= W)
            {
                ans += arr[i].value;
                currWeight += arr[i].weight;
            }
            else if (currWeight + arr[i].weight > W)
            {
                ans += (W - currWeight) * ((double)arr[i].value / (double)arr[i].weight);
                break;
            }
        }
        return ans;
    }
};