// problem link: https://leetcode.com/problems/search-a-2d-matrix/

#include<bits/stdc++.h>
using namespace std;


bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (!matrix.size()) return false;
    int l = 0;
    int h = (matrix.size() * matrix[0].size()) - 1;

    while (l <= h) {
        int mid = (l + (h - l) / 2);
        if (matrix[mid / matrix[0].size()][mid % matrix[0].size()] == target)
            return true;
        if (matrix[mid / matrix[0].size()][mid % matrix[0].size()] < target)
            l = mid + 1;
        else
            h = mid - 1;
    }
    return false;
}