// problem link: https://leetcode.com/problems/palindrome-partitioning-ii/

#include<bits/stdc++.h>
using namespace std;

// optimised

class Solution {
public:
    int t[2001][2001];

    bool isPalindrome(string s, int i, int j)
    {
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    int solve(string s, int i, int j)
    {
        if (i >= j)
            return t[i][j] = 0;
        // whole string is palindrome then no need to partition
        if (isPalindrome(s, i, j) == true)
            return t[i][j] = 0;

        if (t[i][j] != -1)
            return t[i][j];

        int mn = INT_MAX;
        for (int ind = i; ind <= j - 1; ind++)
        {
            int left, right;
            if (t[i][ind] != -1)
                left = t[i][ind];
            else
                left = solve(s, i, ind);

            if (t[ind + 1][j] != -1)
                right = t[ind + 1][j];
            else
                right = solve(s, ind + 1, j);
            // current partition + no. of partitions required for left and right
            int temp = 1 + left + right;
            mn = min(mn, temp);
        }

        return t[i][j] = mn;
    }

    int minCut(string s) {
        memset(t, -1, sizeof(t));
        return solve(s, 0, s.size() - 1);
    }
};