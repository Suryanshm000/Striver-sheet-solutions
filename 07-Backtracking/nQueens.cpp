// problem link: https://leetcode.com/problems/n-queens/

#include<bits/stdc++.h>
using namespace std;


void solve(int col, vector<string> &board, vector<vector<string>> &ans,
           vector<int> &leftRow,
           vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int n)
{
    if (col == n) {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++) {
        if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0
                && upperDiagonal[n - 1 + col - row] == 0) {

            board[row][col] = 'Q';
            // filling hash table
            leftRow[row] = 1;
            lowerDiagonal[row + col] = 1;
            upperDiagonal[n - 1 + col - row] = 1;

            // after placing a queen move to other column
            solve(col + 1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);

            // after backtrack remove precious placed queen
            board[row][col] = '.';
            leftRow[row] = 0;
            lowerDiagonal[row + col] = 0;
            upperDiagonal[n - 1 + col - row] = 0;
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');
    for (int i = 0; i < n; i++) {
        board[i] = s;
    }
    // hashing of upper , lower left diagonal and left row
    vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
    solve(0, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
    return ans;
}
