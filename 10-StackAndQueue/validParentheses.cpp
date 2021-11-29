// problem link: https://leetcode.com/problems/valid-parentheses/

#include<bits/stdc++.h>
using namespace std;


bool isValid(string s) {
    stack<char>st;
    char x;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            st.push(s[i]);
            continue;
        }

        if (st.empty())
            return false;

        if (s[i] == ')')
        {
            x = st.top();
            st.pop();
            if (x == '[' || x == '{')
                return false;
        }

        else if (s[i] == '}')
        {
            x = st.top();
            st.pop();
            if (x == '[' || x == '(')
                return false;
        }

        else if (s[i] == ']')
        {
            x = st.top();
            st.pop();
            if (x == '{' || x == '(')
                return false;
        }
    }
    return st.empty();
}