#cinlude<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        if(!grid.size() || !grid[0].size()) return 0;

        int n = grid.size(), m = grid[0].size(); 

        for (int i = 1; i < m; i++) {
            grid[0][i] += grid[0][i - 1];
        }

        for (int i = 1; i < n; i++) {
            grid[i][0] += grid[i - 1][0];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                grid[i][j] += max(grid[i][j - 1], grid[i - 1][j]);
            }
        }
        return grid[n - 1][m - 1];
    }
};


/*
在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？

 

示例 1:

输入: 
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 12
解释: 路径 1→3→5→2→1 可以拿到最多价值的礼物
 

提示：

0 < grid.length <= 200
0 < grid[0].length <= 200


*/