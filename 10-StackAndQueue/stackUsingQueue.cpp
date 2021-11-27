// problem link: https://leetcode.com/problems/implement-stack-using-queues/
// stack by single queue

#include<bits/stdc++.h>
using namespace std;


class MyStack {
public:

    queue<int> q1;

    MyStack() {
    }

    void push(int x) {
        q1.push(x);
        for (int i = 0; i < q1.size() - 1; i++)
        {
            q1.push(q1.front());
            q1.pop();
        }
    }

    int pop() {
        int t = q1.front();
        q1.pop();
        return t;
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};