// problem link: https://leetcode.com/problems/merge-intervals/

#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> merge(vector<vector<int>>& intervals) {
	vector<vector<int>> ans;
	sort(intervals.begin(), intervals.end());

	vector<int> temp;
	temp = intervals[0];

	for (int i = 1; i < intervals.size(); i++)
	{
		if (temp[1] >= intervals[i][0])
			temp[1] = max(intervals[i][1], temp[1]);
		else
		{
			ans.push_back(temp);
			temp = intervals[i];
		}
	}
	ans.push_back(temp);
	return ans;
}