// problem link: https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    bool static comp(Job j1, Job j2)
    {
        return (j1.profit > j2.profit);
    }

    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n)
    {
        sort(arr, arr + n, comp);
        int mxD = 0;
        for (int i = 0; i < n; i++)
        {
            mxD = max(mxD, arr[i].dead);
        }

        int slot[mxD + 1] = {0};
        for (int i = 0; i < n; i++)
        {
            if (slot[arr[i].dead] == 0)
            {
                slot[arr[i].dead] = arr[i].profit;
                continue;
            }
            int j  = arr[i].dead - 1;
            while (j > 0)
            {
                if (slot[j] == 0)
                {
                    slot[j] = arr[i].profit;
                    break;
                }
                j--;
            }
        }
        vector<int>ans(2, 0);
        for (int i = 1; i <= mxD; i++)
        {
            if (slot[i] != 0) {
                ans[0]++;
                ans[1] += slot[i];
            }
        }
        return ans;
    }
};