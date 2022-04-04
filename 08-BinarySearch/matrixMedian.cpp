// problem link: https://www.interviewbit.com/problems/matrix-median/

#include<bits/stdc++.h>
using namespace std;


int countSmallerThanMid(vector<int> &row, int mid) {
    int l = 0, h = row.size() - 1;
    while (l <= h) {
        int md = (l + h) >> 1;
        if (row[md] <= mid) {
            l = md + 1;
        }
        else {
            h = md - 1;
        }
    }
    return l;
}

int Solution::findMedian(vector<vector<int> > &A) {
    int low = 1;
    int high = INT_MAX;
    int n = A.size();
    int m = A[0].size();

    while (low <= high) {
        int mid = (low + high) >> 1;
        int cnt = 0;
        // counting no. of elements less than equal to mid
        for (int i = 0; i < n; i++) {
            cnt += countSmallerThanMid(A[i], mid);
        }

        // if count is less than equal to n*m/2 then move forward
        if (cnt <= (n * m) / 2) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}