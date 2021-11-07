// problem link: https://leetcode.com/problems/longest-consecutive-sequence/

#include<bits/stdc++.h>
using namespace std;


int longestConsecutive(vector<int>& nums) {
    set<int> s;
    for (auto i : nums)
        s.insert(i);

    int maxSq = 0, currSq = 0;

    for (int i = 0; i < nums.size(); i++)           // {4, 2, 7, 1, 3}
    {
        if (! s.count(nums[i] - 1))
        {
            currSq = 1;
            int currNum = nums[i];
            while (s.count(currNum + 1)) {
                currSq++;
                currNum++;
            }
        }
        maxSq = max(maxSq, currSq);
    }
    return maxSq;
}