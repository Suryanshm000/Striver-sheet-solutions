// problem link: https://leetcode.com/problems/majority-element-ii/

#include<bits/stdc++.h>
using namespace std;


vector<int> majorityElement(vector<int>& nums) {
    int n1 = -1, n2 = -1;
    // atmost 2 diff ele can occur
    int cnt1 = 0, cnt2 = 0;
    for (auto ele : nums)
    {
        if (ele == n1)   cnt1++;

        else if (ele == n2)   cnt2++;

        else if (cnt1 == 0)
        {
            n1 = ele;
            cnt1++;
        }
        else if (cnt2 == 0)
        {
            n2 = ele;
            cnt2++;
        }
        else
        {
            cnt1--;
            cnt2--;
        }
    }

    vector<int>ans;
    cnt1 = cnt2 = 0;
    for (auto ele : nums)
    {
        if (ele == n1)
            cnt1++;
        else if (ele == n2)
            cnt2++;
    }
    // it is possible that any element is less than required times
    if (cnt1 > nums.size() / 3)
        ans.push_back(n1);
    if (cnt2 > nums.size() / 3)
        ans.push_back(n2);

    return ans;
}