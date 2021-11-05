// problem link: https://leetcode.com/problems/powx-n/

#include<bits/stdc++.h>
using namespace std;


double myPow(double x, int n) {
    double ans = 1.0;
    long long cn = n;
    if (cn < 0)  cn *= -1;
    while (cn)
    {
        if (cn % 2)
        {
            ans = ans * x;
            cn--;
        }
        else
        {
            x = x * x;
            cn = cn / 2;
        }
    }
    if (n < 0)
        ans = (double)(1.0) / (double)(ans);

    return ans;
}