// problem link: https://leetcode.com/problems/maximum-subarray/

#include<bits/stdc++.h>
using namespace std;


int maxSubArray(vector<int>& nums) {
	int tempMax = 0, max = INT_MIN;

	for (int i = 0; i < nums.size(); i++)
	{
		tempMax += nums[i];
		if (max < tempMax)
			max = tempMax;
		if (tempMax < 0)
			tempMax = 0;
	}
	return max;
}