// problem link: https://leetcode.com/problems/implement-queue-using-stacks/
// queue using stack pair

#include<bits/stdc++.h>
using namespace std;


class MyQueue {
public:
    stack<int> in, op;
    MyQueue() {

    }

    void push(int x) {
        in.push(x);
    }

    int pop() {
        if (!op.empty())
        {
            int x = op.top();
            op.pop();
            return x;
        }
        while (!in.empty()) {
            op.push(in.top());
            in.pop();
        }
        int x = op.top();
        op.pop();
        return x;
    }

    int peek() {
        if (!op.empty())
            return op.top();

        while (!in.empty()) {
            op.push(in.top());
            in.pop();
        }
        return op.top();
    }

    bool empty() {
        return in.empty() && op.empty();
    }
};
