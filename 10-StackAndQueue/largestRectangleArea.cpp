// problem link: https://leetcode.com/problems/largest-rectangle-in-histogram/

#include<bits/stdc++.h>
using namespace std;


int largestRectangleArea(vector<int>& heights) {

    stack<int> st;
    int maxi = 0;
    int n = heights.size();

    for (int i = 0; i <= n; i++) {
        // if next ele is smaller so pop other ele for maintaining increasing order
        // and also find area
        while (!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
            int height = heights[st.top()];
            st.pop();
            int width;
            if (st.empty()) width = i;
            else width = i - st.top() - 1;

            maxi = max(maxi, width * height);
        }
        // if next element is greater simply push into stack
        st.push(i);
    }
    return maxi;
}