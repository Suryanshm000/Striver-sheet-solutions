// problem link: https://leetcode.com/problems/rotting-oranges/

#include<bits/stdc++.h>
using namespace std;


int orangesRotting(vector<vector<int>>& grid) {
    int mnt = 0, cnt = 0, o = 0;
    int m = grid.size(), n = grid[0].size();
    queue<pair<int, int>> q;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            // counting total oranges
            if (grid[i][j] != 0)
                o++;
            // pushing rotten into queue
            if (grid[i][j] == 2)
                q.push({i, j});
        }

    int lx[] = { -1, 1, 0, 0};
    int ly[] = {0, 0, -1, 1};

    // bfs
    while (!q.empty())
    {
        int size = q.size();
        cnt += size;

        while (size--) {
            int x = q.front().first, y = q.front().second;
            q.pop();

            // traversing up, down, left, right
            for (int i = 0; i < 4; i++)
            {
                int nx = x + lx[i], ny = y + ly[i];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx]                       [ny] != 1)
                    continue;

                grid[nx][ny] = 2;
                q.push({nx, ny});
            }
        }
        // if last elements are connected to new rotten oranges
        if (! q.empty())   mnt++;
    }
    if (cnt == o)
        return mnt;
    return -1;
}