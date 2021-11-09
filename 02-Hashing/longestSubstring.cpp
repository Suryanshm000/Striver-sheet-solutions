// problem link: https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include<bits/stdc++.h>
using namespace std;


int lengthOfLongestSubstring(string s) {
    vector<int> mp(256, -1);
    int len = 0;
    int l = 0, r = 0;

    while (r < s.size()) {
        if (mp[s[r] != -1])                 // if duplicate char is find in map
            l = max(l, mp[s[r]] + 1);
        mp[s[r]] = r;                       // storing and updating index of each char
        len = max(len, r - l + 1);
        r++;
    }
    return len;
}
