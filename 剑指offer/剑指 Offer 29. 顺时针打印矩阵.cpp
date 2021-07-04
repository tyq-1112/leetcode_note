#include <bits/stdc++.h>

using namespace std;

class Solution {

      int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
      vector<int> ans;
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return ans;
        
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m));
        int total = n * m;
        ans = vector<int>(total);

        int x = 0, y = 0;
        int pos = 0;
        for (int i = 0; i < total; i++) {
            ans[i] = matrix[x][y];
            vis[x][y] = true;
            int nx = x + dir[pos][0];
            int ny = y + dir[pos][1];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny]) {
                pos = (pos + 1) % 4;
            }
            x += dir[pos][0];
            y += dir[pos][1];
        }
        return ans;
    }
};



/*
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

 

示例 1：

输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]
示例 2：

输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]
 

限制：

0 <= matrix.length <= 100
0 <= matrix[i].length <= 100


*/
